--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
-- This script will insert the initial data of SwissCube
-- Big endian
-- MSB first


-- TODO: REVIEW AND UPDATE WITH RESPECT TO LATEST DATABASE DEFINITION
--

-- The script will remove all the data from the tables

DELETE FROM t_mission;

INSERT INTO "t_mission" VALUES ( 1, 'QB50', 'SwissCube', 'Swisszerland', 'EPFL', '2009-01-01 00:00:00.000');



DELETE FROM t_satellite;

INSERT INTO "t_satellite" VALUES ( 1, "QB50", "SwissCube cubesat", "qb50", "2009-01-01 00:00:00.000", 1);



-- COM, EPS, CDMS, ADCS and Payload.
DELETE FROM t_subsystem;

INSERT INTO "t_subsystem" VALUES (1, "EPS",      "Power subsystem", 1);
INSERT INTO "t_subsystem" VALUES (2, "ADCS",     "ADCS subsystem", 1);
INSERT INTO "t_subsystem" VALUES (3, "CDMS",     "Command and Data Management System", 1);
INSERT INTO "t_subsystem" VALUES (4, "COM",      "Communications subsystem", 1);
INSERT INTO "t_subsystem" VALUES (5, "Payload",  "Payload", 1);




DELETE FROM t_node;

INSERT INTO "t_node" VALUES (1, "EPS",      "Power subsystem", 1);
INSERT INTO "t_node" VALUES (2, "ADCS",     "ADCS subsystem", 2);
INSERT INTO "t_node" VALUES (3, "CDMS",     "Command and Data Management System", 3);
INSERT INTO "t_node" VALUES (4, "COM",      "Communications subsystem", 4);
INSERT INTO "t_node" VALUES (5, "Payload",  "Payload", 5);



-- COMM LAYERS
DELETE FROM  t_mission_comms_layer;

INSERT INTO t_mission_comms_layer VALUES (1, 'kiss',  'KISS layer',     0, 1, 1);
INSERT INTO t_mission_comms_layer VALUES (2, 'ax.25', 'AX.25 Layer 2',  1, 1, 1);
INSERT INTO t_mission_comms_layer VALUES (3, 'ccsds', 'CCSDS Layer',    2, 1, 1);
-- This layer will use user-defined frames
INSERT INTO t_mission_comms_layer VALUES (4, 'pus',   'PUS ',           3, 0, 1);

-- INSERT INTO t_mission_comms_layer VALUES (4, 'hdlc',   'HDLC ',         0, 3, 1, 1);
-- INSERT INTO t_mission_comms_layer VALUES (4, 'csp',    'CSP',           0, 3, 1, 1);


-- It could be implemented with an array; 0, 1, ... n instead of next, previous
-- Only 1 field, sequence number


