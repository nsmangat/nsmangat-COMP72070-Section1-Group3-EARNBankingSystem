-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema EARNBankingDB
-- -----------------------------------------------------
-- database model / diagram for earn banking accounts & transactions

-- -----------------------------------------------------
-- Schema EARNBankingDB
--
-- database model / diagram for earn banking accounts & transactions
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `EARNBankingDB` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin ;
USE `EARNBankingDB` ;

-- -----------------------------------------------------
-- Table `clients`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `clients` (
  `client_id` INT NOT NULL AUTO_INCREMENT,
  `client_firstName` VARCHAR(45) NOT NULL,
  `client_lastName` VARCHAR(45) NOT NULL,
  `client_email` VARCHAR(45) NULL,
  `phone_number` VARCHAR(45) NULL,
  `client_street` VARCHAR(45) NOT NULL,
  `client_city` VARCHAR(45) NOT NULL,
  `client_province` VARCHAR(45) NOT NULL,
  `client_zipCode` VARCHAR(6) NOT NULL,
  PRIMARY KEY (`client_id`))
ENGINE = InnoDB
COMMENT = 'stores clients all of which have credentials for login.';


-- -----------------------------------------------------
-- Table `account_type`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `account_type` (
  `account_type_id` INT NOT NULL AUTO_INCREMENT,
  `account_name` VARCHAR(45) NULL,
  `account_interest` DOUBLE NULL,
  PRIMARY KEY (`account_type_id`))
ENGINE = InnoDB
COMMENT = 'stores different types for accounts (chequeing, savings, etc).';

INSERT IGNORE INTO `EARNBankingDB`.`account_type` (
	`account_type_id`,
	`account_name`,
    `account_interest`) 
    VALUES 
	(1, 'Chequings', 0.03),
    (2, 'Savings', 0.06);

-- -----------------------------------------------------
-- Table `accounts`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `accounts` (
  `account_id` INT NOT NULL AUTO_INCREMENT,
  `client_id` INT NOT NULL,
  `account_type_id` INT NOT NULL,
  `balance` DOUBLE NULL,
  PRIMARY KEY (`account_id`),
  INDEX `fk_accounts_clients1_idx` (`client_id` ASC) VISIBLE,
  INDEX `fk_accounts_account_type1_idx` (`account_type_id` ASC) INVISIBLE,
  UNIQUE INDEX `account_relation_id` (`client_id` ASC, `account_type_id` ASC) INVISIBLE,
  CONSTRAINT `fk_accounts_clients1`
    FOREIGN KEY (`client_id`)
    REFERENCES `clients` (`client_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_accounts_account_type1`
    FOREIGN KEY (`account_type_id`)
    REFERENCES `account_type` (`account_type_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
COMMENT = 'stores accounts, all of which are tied to an associated client (user).';


-- -----------------------------------------------------
-- Table `invoice_type`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `invoice_type` (
  `invoice_type_id` INT NOT NULL AUTO_INCREMENT,
  `invoice_name` VARCHAR(45) NULL,
  PRIMARY KEY (`invoice_type_id`))
ENGINE = InnoDB
COMMENT = 'stores different types for invoices / transactions (deposit, withdraw, transfer, etc).';


INSERT IGNORE INTO `EARNBankingDB`.`invoice_type` (
	`invoice_name`) 
    VALUES 
	('E-Transfer'),
    ('Cheque'),
    ('Withdraw'),
    ('Account-Transfer');
    
-- -----------------------------------------------------
-- Table `invoices`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `invoices` (
  `invoice_id` INT NOT NULL AUTO_INCREMENT,
  `account_id` INT NOT NULL,
  `invoice_type_id` INT NOT NULL,
  `invoice_time` TIMESTAMP,
  `previous_balance` DOUBLE NOT NULL,
  `new_balance` DOUBLE NOT NULL,
  `secondary_account_id` INT NOT NULL,
  PRIMARY KEY (`invoice_id`),
  INDEX `fk_invoices_accounts1_idx` (`account_id` ASC) VISIBLE,
  INDEX `fk_invoices_invoice_type1_idx` (`invoice_type_id` ASC) VISIBLE,
  CONSTRAINT `fk_invoices_accounts1`
    FOREIGN KEY (`account_id`)
    REFERENCES `accounts` (`account_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_invoices_invoice_type1`
    FOREIGN KEY (`invoice_type_id`)
    REFERENCES `invoice_type` (`invoice_type_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
COMMENT = 'stores invoices / transactions all of which are tied to an associated account';


-- -----------------------------------------------------
-- Table `credentials`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `credentials` (
  `credential_id` INT NOT NULL AUTO_INCREMENT,
  `client_id` INT NOT NULL,
  `client_password_hash` VARCHAR(45) NOT NULL,
  `client_usernumber` INT NOT NULL,
  `client_username` VARCHAR(45) NULL,
  PRIMARY KEY (`credential_id`),
  CONSTRAINT uk_usernumber_password_hash UNIQUE (`client_usernumber`,`client_password_hash`),
  CONSTRAINT uk_username_password_hash UNIQUE (`client_username`,`client_password_hash`),
  INDEX `fk_credentials_clients_idx` (`client_id` ASC) VISIBLE,
  CONSTRAINT `fk_credentials_clients`
    FOREIGN KEY (`client_id`)
    REFERENCES `clients` (`client_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB
COMMENT = 'stores login info and is used to get associated client for validation.';

USE `EARNBankingDB` ;

-- -----------------------------------------------------
-- procedure getClientInfo
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `getClientInfo`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `getClientInfo` (
	IN input_client_id INT)
BEGIN
	Select * FROM clients c WHERE c.client_id = input_client_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure getAccountInfo
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `getAccountInfo`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `getAccountInfo` (
	IN input_account_id INT)
BEGIN
	Select * FROM accounts a WHERE a.account_id = input_account_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure getTransactionInfo
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `getTransactionInfo`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `getTransactionInfo` (
	IN input_transaction_id INT)
BEGIN
	Select * FROM invoices i WHERE i.invoice_id = input_transaction_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure getAllClientsInfo
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `getAllClientsInfo`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `getAllClientsInfo` ()
BEGIN
	Select * FROM clients;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure getAccountsForClient
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `getAccountsForClient`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `getAccountsForClient` (
	IN input_client_id INT)
BEGIN
	SELECT * FROM accounts a where a.client_id = input_client_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure getTransactionsForAccount
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `getTransactionsForAccount`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `getTransactionsForAccount` (
	IN input_account_id INT)
BEGIN
	SELECT * FROM invoices i where i.account_id = input_account_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure checkLoginNamePass
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `checkLoginNamePass`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `checkLoginNamePass` (
	IN input_Username VARCHAR(45),
    IN input_Password VARCHAR(45),
    OUT received_client_id INT)
BEGIN
	SET received_client_id := (Select c.client_id FROM credentials c WHERE (input_username = c.client_username) AND (input_password = c.client_password_hash));
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure checkLoginNumberPass
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `checkLoginNumberPass`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `checkLoginNumberPass` (
	IN input_usernumber INT,
    IN input_Password VARCHAR(45),
    OUT received_client_id INT)
BEGIN
	SET received_client_id := (Select c.client_id FROM credentials c WHERE (input_usernumber = c.client_usernumber) AND (input_password = c.client_password_hash));
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure addClient
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `addClient`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `addClient` (
	IN input_firstName VARCHAR(45),
    IN input_lastName VARCHAR(45),
    IN input_email VARCHAR(45),
    IN input_phone_number VARCHAR(45),
    IN input_street VARCHAR(45),
    IN input_city VARCHAR(45),
    IN input_province VARCHAR(45),
    IN input_zipCode VARCHAR(6),
    OUT new_client_id INT)
BEGIN
	#first create user
	INSERT INTO clients (client_firstName, client_lastName, client_email, phone_number, client_street, client_city, client_province, client_zipCode)
		VALUE (input_firstName, input_lastName, input_email, input_phone_number, input_street, input_city, input_province, input_zipCode);
	
    SET new_client_id := last_insert_id();	# returns client's new ID
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure addAccount
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `addAccount`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `addAccount`(
	IN input_client_id INT,
	IN input_account_type INT,
    OUT new_account_id INT)
BEGIN
	DECLARE checkValue BOOL DEFAULT false;
    SET new_account_id := NULL;	#in case it has already been set
    
    #check if client exists otherwise return nothing for generated_id
    CALL checkClientExists(input_client_id, checkValue);
	IF ( checkValue ) THEN
		BEGIN
			INSERT INTO accounts (client_id, account_type_id, balance)
				Value (input_client_id, input_account_type, 0);
			
            SET new_account_id := LAST_INSERT_ID();	# returns account's new id
		END;
	END IF;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure addTransaction
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `addTransaction`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `addTransaction`(
	IN input_account_id INT,
    IN input_type_id INT,
    IN input_time TIMESTAMP,
    IN input_previous_balance DOUBLE,
    IN input_new_balance DOUBLE,
    IN input_secondary_id INT,
    OUT new_transaction_id INT)
BEGIN
	DECLARE checkValue BOOL DEFAULT false;
    
	#first check if account exists otherwise don't create invoice
    CALL checkAccountExists(input_account_id, checkValue);
	IF ( checkValue ) THEN
		BEGIN
			INSERT INTO invoices (account_id, invoice_type_id, invoice_time, previous_balance, new_balance, secondary_account_id)
				Value (input_account_id, input_type_id, input_time, input_previous_balance, input_new_balance, input_secondary_id);
			SET new_transaction_id := last_insert_id();
		END;
	END IF;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure deleteTransaction
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `deleteTransaction`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `deleteTransaction` (
	IN input_transaction_id INT)
BEGIN
	DELETE FROM invoices i where i.invoice_id = input_transaction_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure deleteAccount
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `deleteAccount`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `deleteAccount` (
	IN input_account_id INT)
BEGIN
	DELETE FROM invoices i where i.account_id = input_account_id;	#delete all associated accounts, then delete account itself
    
	DELETE FROM accounts a where a.account_id = input_account_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure deleteClient
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `deleteClient`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `deleteClient` (
	IN input_client_id INT)
BEGIN
	# delete info backwards to ensure everything is gone after
	DELETE FROM invoices i WHERE i.account_id in (Select a.account_id FROM accounts a WHERE a.client_id = input_client_id);	#delete all associated accounts, then delete account itself
	
    DELETE FROM accounts a WHERE a.client_id = input_client_id;
	
    DELETE FROM credentials cr WHERE cr.client_id = input_client_id;
	
    DELETE FROM clients cl WHERE cl.client_id = input_client_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure updateTransaction
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `updateTransaction`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `updateTransaction` (
	IN input_transaction_id INT,
    IN input_account_id INT,
    IN input_type_id INT,
    IN input_time TIMESTAMP,
    IN input_previous_balance DOUBLE,
    IN input_new_balance DOUBLE,
    IN input_secondary_id INT)
BEGIN
	UPDATE invoices i SET 
		i.invoice_type_id = input_type_id,
        i.invoice_time = input_time,
		i.previous_balance = input_previous_balance,
		i.new_balance = input_new_balance,
		i.secondary_account_id = input_secondary_id
		WHERE i.invoice_id = input_transaction_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure updateClient
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `updateClient`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `updateClient` (
	IN input_client_id INT,
	IN input_firstName VARCHAR(45),
    IN input_lastName VARCHAR(45),
    IN input_email VARCHAR(45),
    IN input_number VARCHAR(45),
    IN input_street VARCHAR(45),
    IN input_city VARCHAR(45),
    IN input_province VARCHAR(45),
    IN input_zipCode VARCHAR(6))
BEGIN
	UPDATE clients c SET
		c.client_firstName = input_firstName,
		c.client_lastName = input_lastName,
		c.client_email = input_email,
		c.phone_number = input_number,
		c.client_street = input_street,
		c.client_city = input_city,
        c.client_province = input_province,
		c.client_zipCode = input_zipCode
		WHERE c.client_id = input_client_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure updateAccount
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `updateAccount`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `updateAccount`(
	IN input_account_id INT,
    IN input_client_id INT,
	IN input_account_type INT,
    IN input_balance DOUBLE)
BEGIN
	UPDATE accounts a SET
		a.client_id = input_client_id,
		a.account_type_id = input_account_type,
		a.balance = input_balance
		WHERE a.account_id = input_account_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure addCredential
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `addCredential`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `addCredential` (
	IN input_client_id INT,
    IN input_username VARCHAR(45),
    IN input_usernumber INT,
    IN input_password_hash VARCHAR(45),
    OUT new_credential_id INT)
BEGIN
	DECLARE checkValue BOOL DEFAULT false;
    
	#first check if client exists to create credentials otherwise don't create them
    CALL checkClientExists(input_client_id, checkValue);
	IF ( checkValue ) THEN
		BEGIN
			INSERT INTO credentials (client_id, client_password_hash, client_usernumber, client_username)
				VALUE (input_client_id, input_password_hash, input_usernumber, input_username);
            SET new_credential_id := LAST_INSERT_ID();	# returns credentials's new id
		END;
	END IF;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure updateCredential
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `updateCredential`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `updateCredential` (
	IN input_client_id INT,
    IN input_username VARCHAR(45),
    IN input_usernumber INT,
    IN input_password_hash VARCHAR(45))
BEGIN
	UPDATE credentials c SET
		c.client_password_hash = input_password_hash,
		c.client_usernumber = input_usernumber,
		c.client_username = input_username
		WHERE c.client_id = input_client_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure checkClientExists
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `checkClientExists`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `checkClientExists` (
	IN check_client_id INT,
    OUT check_result BOOL)
BEGIN
	IF( EXISTS
		(SELECT c.client_id FROM clients c WHERE c.client_id = check_client_id))
		THEN SET check_result = TRUE;
		ELSE SET check_result = FALSE;
    END IF;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure checkAccountExists
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `checkAccountExists`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `checkAccountExists` (
	IN check_account_id INT,
    OUT check_result BOOL)
BEGIN
	IF( EXISTS
		(SELECT a.account_id FROM accounts a WHERE a.account_id = check_account_id))
		THEN SET check_result = TRUE;
		ELSE SET check_result = FALSE;
    END IF;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure checkCredentialExists
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `checkCredentialExists`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `checkCredentialExists` (
	IN check_credential_id INT,
    OUT check_result BOOL)
BEGIN
	IF( EXISTS
		(SELECT credential_id FROM credentials c WHERE c.credential_id = check_credential_id))
		THEN SET check_result = TRUE;
		ELSE SET check_result = FALSE;
    END IF;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure checkTransactionExists
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `checkTransactionExists`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `checkTransactionExists` (
	IN check_transaction_id INT,
    OUT check_result BOOL)
BEGIN
	IF( EXISTS
		(SELECT i.invoice_id FROM invoices i WHERE i.invoice_id = check_transaction_id))
		THEN SET check_result = TRUE;
		ELSE SET check_result = FALSE;
    END IF;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure deleteCredential
-- -----------------------------------------------------

DROP PROCEDURE IF EXISTS `deleteCredential`;

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `deleteCredential` (IN input_credential_id INT)
BEGIN
	DELETE FROM credentials c WHERE c.credential_id = input_credential_id;
END$$

DELIMITER ;

-- -----------------------------------------------------
-- procedure getCredentialInfo
-- -----------------------------------------------------

DELIMITER $$
USE `EARNBankingDB`$$
CREATE PROCEDURE `getCredentialInfo` (
	IN input_credential_id INT)
BEGIN
	Select * FROM credentials c WHERE c.credential_id = input_credential_id;
END$$

DELIMITER ;

DROP USER IF EXISTS 'EARNDBReader';
CREATE USER 'EARNDBReader' IDENTIFIED BY 'Gcugy6/fA{KR9H(r|:1Gp^qyd';
GRANT SELECT ON TABLE * TO 'EARNDBReader';
GRANT EXECUTE ON * TO 'EARNDBReader';

DROP USER IF EXISTS 'EARNDBWriter';
CREATE USER 'EARNDBWriter' IDENTIFIED BY '|RI?BEe8drU0JoD~_j*|=fS@=';
GRANT SELECT, INSERT, TRIGGER, UPDATE, DELETE ON TABLE * TO 'EARNDBWriter';
GRANT EXECUTE ON * TO 'EARNDBWriter';

DROP USER IF EXISTS 'EARNDBValidation';
CREATE USER 'EARNDBValidation' IDENTIFIED BY '@:+fA,UFr[xn_[3>QwBuB#9qi';
GRANT SELECT, UPDATE, INSERT, DELETE, TRIGGER ON TABLE `EARNBankingDB`.`credentials` TO 'EARNDBValidation';
GRANT SELECT ON TABLE * TO 'EARNDBValidation';
GRANT EXECUTE ON * TO 'EARNDBValidation';

DROP USER IF EXISTS 'EARNDBAdmin';
CREATE USER 'EARNDBAdmin' IDENTIFIED BY '=&gvxgIDY/^zZRKItYLLsXv3o';
GRANT ALL ON * TO 'EARNDBAdmin';

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
