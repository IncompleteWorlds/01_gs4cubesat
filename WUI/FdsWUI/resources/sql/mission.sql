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


DROP TABLE  IF EXISTS t_subsystem;
DROP TABLE  IF EXISTS t_satellite;
DROP TABLE  IF EXISTS t_mission;




-- ##########################################
-- Mission definitions
-- ##########################################

CREATE TABLE t_mission (
    name              VARCHAR(40) PRIMARY KEY,
    description       VARCHAR(80),
    country           VARCHAR(40),
    owner	          VARCHAR(60) NOT NULL,
    creation_date     DATETIME NOT NULL,
    admin_identifier  INTEGER NOT NULL,
    email_address     VARCHAR(60),
    phone_number      VARCHAR(20)
);


-- A Satellite belongs to a Mission

CREATE TABLE t_satellite (
    name	          VARCHAR(40) PRIMARY KEY,
    description	      VARCHAR(80),
    code	          VARCHAR(10) NOT NULL UNIQUE,
    launch_date	      DATETIME NOT NULL,
    
    mission_name	  VARCHAR(40) NOT NULL
);



-- A Subsystem belongs to a Satellite

CREATE TABLE t_subsystem (
    name            VARCHAR(40) PRIMARY KEY,
    description     VARCHAR(80),
    
    satellite_name  VARCHAR(40) NOT NULL
);



-- A Node belongs to a Subsystem
--DROP TABLE  IF EXISTS t_node;
--
--CREATE TABLE t_node (
--    identifier       INTEGER PRIMARY KEY,
--    name             VARCHAR NOT NULL,
--    description      VARCHAR,
--
--    subsystem_name   VARCHAR NOT NULL,
--    FOREIGN KEY(subsystem_name) REFERENCES t_subsystem(name) ON DELETE CASCADE
--);



-- Communication Layers of a Satellite
-- It has a set of Configuration Parameters
--DROP TABLE  IF EXISTS t_mission_comms_layer;
--
--CREATE TABLE t_mission_comms_layer (
--    name	         VARCHAR PRIMARY KEY,
--    description    VARCHAR,
--
--    sequence_number  INTEGER NOT NULL,
--
--    -- 1 - Fix format, 0 - User defined format via FramesDefinitions
--    default_flag INTEGER NOT NULL,
--
--    mission_name	VARCHAR NOT NULL,
--    FOREIGN KEY(mission_name) REFERENCES t_mission(name)
--);
--
-- List of Default layers
-- They are implemented by default in the TM Decoder
--INSERT INTO t_mission_comms_layer VALUES ("HDLC",  "Default HDLC  layer", 0, 1, "all missions");
--INSERT INTO t_mission_comms_layer VALUES ("AX.25", "Default AX.25 layer", 0, 1, "all missions");
--INSERT INTO t_mission_comms_layer VALUES ("KISS",  "Default KISS  layer", 0, 1, "all missions");
--INSERT INTO t_mission_comms_layer VALUES ("CSP",   "Default CSP   layer", 0, 1, "all missions");
--INSERT INTO t_mission_comms_layer VALUES ("CCSDS", "Default CCSDS layer", 0, 1, "all missions");



-- ===============================================================
-- Add FOREIGN KEYS
-- ===============================================================
ALTER TABLE t_mission 
    ADD CONSTRAINT t_mission_c1
        FOREIGN KEY(admin_identifier) REFERENCES t_user(identifier);

ALTER TABLE t_satellite
    ADD CONSTRAINT t_satellite_c1
        FOREIGN KEY(mission_name) REFERENCES t_mission(name) ON DELETE CASCADE;


ALTER TABLE t_subsystem
    ADD CONSTRAINT t_subsystem_c1
        FOREIGN KEY(satellite_name) REFERENCES t_satellite(name) ON DELETE CASCADE;


SET FOREIGN_KEY_CHECKS = 1;

