--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--

-- Mission definitions
-- ##########################################


DROP TABLE  IF EXISTS "t_mission";

CREATE TABLE "t_mission" (
    'name'              TEXT PRIMARY KEY,
    'description'       TEXT,
    'country'           TEXT,
    'owner'	            TEXT NOT NULL,
    'creation_date'	    TEXT NOT NULL,
    'admin_identifier'  INTEGER NOT NULL,
    'email_address'     TEXT,
    'phone_number'      TEXT,
    
    FOREIGN KEY('admin_identifier') REFERENCES t_user(identifier)
);


-- A Satellite belongs to a Mission
DROP TABLE  IF EXISTS "t_satellite";

CREATE TABLE "t_satellite" (
    'name'	        TEXT PRIMARY KEY,
    'description'	TEXT,
    'code'	        TEXT NOT NULL UNIQUE,
    'launch_date'	TEXT NOT NULL,

    'mission_name'	TEXT NOT NULL,
    FOREIGN KEY('mission_name') REFERENCES t_mission(name) ON DELETE CASCADE
);



-- A Subsystem belongs to a Satellite
DROP TABLE  IF EXISTS "t_subsystem";

CREATE TABLE "t_subsystem" (
    'name'            TEXT PRIMARY KEY,
    'description'     TEXT,
    
    'satellite_name'  TEXT NOT NULL,
    
    FOREIGN KEY('satellite_name') REFERENCES t_satellite(name) ON DELETE CASCADE
);



-- A Node belongs to a Subsystem
DROP TABLE  IF EXISTS "t_node";

CREATE TABLE "t_node" (
    'identifier'       INTEGER PRIMARY KEY,
    'name'             TEXT NOT NULL,
    'description'      TEXT,

    'subsystem_name'   TEXT NOT NULL,
    FOREIGN KEY('subsystem_name') REFERENCES t_subsystem(name) ON DELETE CASCADE
);



-- Communication Layers of a Satellite
-- It has a set of Configuration Parameters
DROP TABLE  IF EXISTS "t_mission_comms_layer";

CREATE TABLE "t_mission_comms_layer" (
    'name'	         TEXT PRIMARY KEY,
    'description'    TEXT,

    'sequence_number'  INTEGER NOT NULL,

    -- 1 - Fix format, 0 - User defined format via FramesDefinitions
    'default_flag' INTEGER NOT NULL,

    'mission_name'	TEXT NOT NULL,
    FOREIGN KEY('mission_name') REFERENCES t_mission(name)
);

-- List of Default layers
-- They are implemented by default in the TM Decoder
INSERT INTO "t_mission_comms_layer" VALUES ("HDLC",  "Default HDLC  layer", 0, 1, "all missions");
INSERT INTO "t_mission_comms_layer" VALUES ("AX.25", "Default AX.25 layer", 0, 1, "all missions");
INSERT INTO "t_mission_comms_layer" VALUES ("KISS",  "Default KISS  layer", 0, 1, "all missions");
INSERT INTO "t_mission_comms_layer" VALUES ("CSP",   "Default CSP   layer", 0, 1, "all missions");
INSERT INTO "t_mission_comms_layer" VALUES ("CCSDS", "Default CCSDS layer", 0, 1, "all missions");



