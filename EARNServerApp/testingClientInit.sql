CALL `earnbankingdb`.`addClient`('bob', 'joe', 'bobjoe@joebob.bob', '123-456-7890', '123Alphabetstreet', 'toronto', 'ontario', '1b2c3d', @newClientID);
SELECT @newClientID;

CALL `earnbankingdb`.`addCredential`(@newClientID, 'bobjoe123', 2087432239, 'password', @newCredentialID);
SELECT @newCredentialID;

CALL `earnbankingdb`.`addAccount`(@newClientID, 1, @newChequingID);

CALL `earnbankingdb`.`addAccount`(@newClientID, 2, @newSavingsID);