DROP DATABASE /*! IF EXISTS */ employeedb;
DROP DATABASE /*! IF EXISTS */ employeedb;

CREATE DATABASE employeedb;

USE employeedb;

CREATE TABLE employeepersonaldata (
 employeeID INT UNSIGNED AUTO_INCREMENT,
 titel   VARCHAR(20)  NOT NULL,
 salution  VARCHAR(30)  NOT NULL,
 forename  VARCHAR(30)  NOT NULL,
 surname   VARCHAR(30)  NOT NULL,
 birthday  DATE   ,
 bithplace  VARCHAR(40)  ,
 gender    VARCHAR(20)  ,
 familystatus VARCHAR(20)  ,
 streetandnumber VARCHAR(40) NOT NULL,
 postalcode  INT(5)   ZEROFILL NOT NULL,
 city   VARCHAR(40)  NOT NULL,
 PrivatTelefon VARCHAR(20)  NOT NULL,
 PrivatEmail  VARCHAR(30) ,
 PRIMARY KEY (employeeID)
) AUTO_INCREMENT=1000 ENGINE=InnoDB;

CREATE TABLE employeeworkdata (
 workdataID  INT UNSIGNED AUTO_INCREMENT,
 workEmail  VARCHAR(20)  NOT NULL,
 officephone   VARCHAR(20)  NOT NULL,
 departement   VARCHAR(20)  NOT NULL,
 photo    VARCHAR(20)  ,
 office    VARCHAR(20)  ,
 officefloor  INT(5),
  PRIMARY KEY (workdataID)
) AUTO_INCREMENT=1000 ENGINE=InnoDB;

CREATE TABLE employeesecuritydata (
 securityID  INT  UNSIGNED AUTO_INCREMENT,
 securitylevel INT  NOT NULL,
 keynumber  INT NOT NULL,
 lastUsedDoor INT(10)   ,
 lastUsed  DATETIME  ,
 firstUsed  DATETIME  ,
 validat  DATE   NOT NULL,
 validto  DATE   NOT NULL,
 startofWork  TIME   NOT NULL DEFAULT '07:00:00',
 endofwork  TIME   NOT NULL DEFAULT '22:00:00',
 weekendwork BOOL   NOT NULL,
 employeeID INT UNSIGNED,
 PRIMARY KEY (securityID),
 FOREIGN KEY (employeeID) REFERENCES employeepersonaldata (employeeID)
) AUTO_INCREMENT=1000 ENGINE=InnoDB;

CREATE TABLE associated (
 employeeID INT UNSIGNED,
 workdataID INT UNSIGNED,
 PRIMARY KEY(employeeID, workdataID),
 FOREIGN KEY (employeeID) REFERENCES employeepersonaldata (employeeID),
 FOREIGN KEY (workdataID) REFERENCES employeeworkdata (workdataID)
) ENGINE=InnoDB;
