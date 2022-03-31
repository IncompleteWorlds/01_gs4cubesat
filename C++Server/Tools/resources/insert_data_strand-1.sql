--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
-- This script will insert the initial data of Strand-1 mission
-- Big endian
-- MSB first


-- ***********************************************************
--
--      MISSION:  STRAND-1
--
-- ***********************************************************


-- The script will remove all the data from the tables

DELETE FROM t_mission WHERE name = "Strand-1";

INSERT INTO t_mission ("identifier", "name", "description", "country", "owner", "creation_date") 
       VALUES (3, "Strand-1", "Strand-1 SSC", "UK", "Surrey Space Centre", "2013-01-01 00:00:00.000");


DELETE FROM t_satellite WHERE name = "Strand-1";

INSERT INTO t_satellite ("identifier", "name", "description", "code", "launch_date","mission_id")
     VALUES (3, "Strand-1", "Strand-1 cubesat", "st01", "2009-01-01 00:00:00.000", 3);
    


-- OBC, Modem
DELETE FROM t_subsystem WHERE satellite_id = 3;

INSERT INTO t_subsystem ("identifier", "name", "description", "satellite_id")
     VALUES (1, "Modem", "Modem subsystem", 3);
     
INSERT INTO t_subsystem ("identifier", "name", "description", "satellite_id")
     VALUES (2, "OBC", "OBC subsystem", 3);




DELETE FROM t_node;

INSERT INTO t_node (`identifier`,`name`,`description`,`subsystem_id`)
     VALUES (1, "EPS", "Power subsystem", 2);

INSERT INTO t_node (`identifier`,`name`,`description`,`subsystem_id`)
     VALUES (2, "Battery", "Battery subsystem", 2);

INSERT INTO t_node (`identifier`,`name`,`description`,`subsystem_id`)
     VALUES (3, "COM",     "Switch board", 2);




-- COMM LAYERS
DELETE FROM  t_mission_comms_layer WHERE mission_id = 3;

-- Standard layers
INSERT INTO t_mission_comms_layer ("identifier","name","description","sequence_number","mission_id")
     VALUES (1, "kiss",  "KISS layer", 0, 3);

-- User defined layers
INSERT INTO t_mission_comms_layer ("identifier","name","description","sequence_number","mission_id")
     VALUES (2, "hdlc_upd",  "Updated HDLC frame types", 1, 3);

-- Note: This layer depends on the value of a field
INSERT INTO t_mission_comms_layer ("identifier","name","description","sequence_number","mission_id")
     VALUES (3, "obc_layer",  "OBC Layer", 2, 3);

-- Note: This layer depends on the value of a field
INSERT INTO t_mission_comms_layer ("identifier","name","description","sequence_number","mission_id")
     VALUES (4, "beacon_layer",  "Beacon Layer", 3, 3);



