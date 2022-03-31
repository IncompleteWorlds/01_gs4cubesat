--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2021 Incomplete Worlds
--
-- Taylor for MariaDB/MySQL
--

USE common_db;

# Tell mysql to ignore foreign keys for a little while
SET FOREIGN_KEY_CHECKS = 0;

DROP TABLE IF EXISTS t_user;
DROP TABLE  IF EXISTS t_role_function;
DROP TABLE  IF EXISTS t_app_function;



-- ##########################################
-- Users, Roles & Functions definitions
-- ##########################################

-- Users of a Mission

CREATE TABLE t_user (
    identifier     INTEGER PRIMARY KEY AUTO_INCREMENT,

    -- Login details
    user_name      VARCHAR(30) NOT NULL UNIQUE,
    password       VARCHAR(256) NOT NUll,

    -- Person details
    first_name     VARCHAR(40) NOT NULL,
    last_name      VARCHAR(40) NOT NULL,

    email_address  VARCHAR(60) NOT NULL,

    logged_flag    BOOL NOT NULL DEFAULT 0,

    -- Mission user is working on 
    -- Only for Mission related roles
    -- mission_name   VARCHAR(40) NOT NULL,
    role_id        INTEGER NOT NULL
);



DROP TABLE  IF EXISTS t_role;

--  0 = Administrator 
--  1 = Normal user
--  2 = Read Only
--
--  10 = Mission Administrator 
--  11 = Mission Operator
--  12 = Mission Read Only
--
CREATE TABLE t_role (
    identifier    INTEGER PRIMARY KEY AUTO_INCREMENT,

    name          VARCHAR(40) NOT NULL,
    description   VARCHAR(80)
);


-- It identifies a function of an application
CREATE TABLE t_app_function (
    identifier       INTEGER PRIMARY KEY AUTO_INCREMENT,

    name             VARCHAR(40) NOT NULL,
    description      VARCHAR(80),
    
    application_id   INTEGER NOT NULL
);


-- It identifies an application. I.e. MCS, FDS, Tools, etc.
DROP TABLE  IF EXISTS t_application;

CREATE TABLE t_application (
    identifier    INTEGER PRIMARY KEY AUTO_INCREMENT,

    name          VARCHAR(40) NOT NULL,
    description   VARCHAR(80)
);


-- It describes application functions of a role
CREATE TABLE t_role_function (
    role_id       INTEGER NOT NULL,
    function_id   INTEGER NOT NULL,

    PRIMARY KEY(role_id, function_id)
);


-- ===============================================================
-- Add FOREIGN KEYS
-- ===============================================================
ALTER TABLE t_user 
    ADD CONSTRAINT t_user_c1
        FOREIGN KEY(role_id) REFERENCES t_role(identifier);

ALTER TABLE t_app_function
    ADD CONSTRAINT t_app_function_c1
        FOREIGN KEY(application_id) REFERENCES t_application(identifier);

ALTER TABLE t_role_function
    ADD CONSTRAINT t_role_function_c1
        FOREIGN KEY(role_id) REFERENCES t_role(identifier);

ALTER TABLE t_role_function
    ADD CONSTRAINT t_role_function_c2
        FOREIGN KEY(function_id) REFERENCES t_app_function(identifier);


SET FOREIGN_KEY_CHECKS = 1;

