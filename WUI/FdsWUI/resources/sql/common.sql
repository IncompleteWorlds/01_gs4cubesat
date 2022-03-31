--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
-- Taylor for MariaDB/MySQL
--


USE common_db;

-- ##########################################
-- Common and general definitions
-- ##########################################

DROP TABLE  IF EXISTS t_configuration_parameters;

CREATE TABLE t_configuration_parameters (
    identifier     INTEGER PRIMARY KEY AUTO_INCREMENT,

    par_name       VARCHAR(40) NOT NULL UNIQUE,
    description    VARCHAR(80),
    par_value      VARCHAR(80) NOT NUll,
    par_type       INTEGER NOT NULL,

    -- Owner of the parameter. It can be an user, mission, system, etc.
    user_id        INTEGER,
    misison_name   VARCHAR(40),
    layer_name     VARCHAR(40)
);

