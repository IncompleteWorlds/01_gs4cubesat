--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--


-- Frames definitions
-- ##########################################


DROP TABLE  IF EXISTS "t_frame";

-- It describes a TC or TM frame as a set of Fields (Parameters).
-- Each field is related to a TM or TC parameter
-- See
-- Alias 'container'
CREATE TABLE "t_frame" (
    -- container name
    'name'	TEXT PRIMARY KEY,
    
    'description'   TEXT,

    -- In milliseconds
    'expected_interval'  INTEGER,

    -- 0 - Variable, N - Fix length
    'length_bits'	INTEGER NOT NULL,
    
    'flag'          INTEGER,

    -- 0 - TM frame, 1 - TC frame, 2 - TM and TC
    'hktm_flag'	INTEGER NOT NULL,
    
    'layer_name'   TEXT NOT NULL,

    FOREIGN KEY('layer_name') REFERENCES t_mission_comms_layer(name)
    
    -- 0 - None
    -- 'start_delimiter'	INTEGER NOT NULL,
    -- 0 - None
    -- 'end_delimiter'	INTEGER NOT NULL,

    -- It identifies the type of the frame
    -- 'identification_value'	INTEGER NOT NULL,
    -- 'identification_field'	INTEGER NOT NULL

    -- Subsystem identifier
    -- 'subsystem_name'  INTEGER NOT NULL,

    -- FOREIGN KEY('subsystem_name') REFERENCES t_subsystem(name) ON DELETE CASCADE
);


-- It describes the fields belonging to a TM frame
-- Alias 'parameter'
DROP TABLE IF EXISTS "t_frame_parameter";

CREATE TABLE "t_frame_parameter" (
    'frame_name'          TEXT NOT NULL,
    'parameter_name'      TEXT NOT NULL,

    -- In bits from previous parameter, starting from 0
    'relative_position'   INTEGER NOT NULL,
    
    PRIMARY KEY('frame_name', 'parameter_name'),

    FOREIGN KEY('frame_name') REFERENCES t_frame_definition(name)   ON DELETE CASCADE
    FOREIGN KEY('parameter_name') REFERENCES t_tm_parameter(name)
);


-- Conditions to be met. i.e. apid==5
-- Specify the conditions that a packet has to fulfill for this container
-- It defines a set of conditions a stream of bytes has to fulfil to create the container
DROP TABLE IF EXISTS "t_frame_condition";

CREATE TABLE "t_frame_condition" (
    'frame_name'            TEXT PRIMARY KEY,
    'condition_text'        TEXT NOT NULL,
    
    'parameter_name'        TEXT NOT NULL,
    'parameter_value'       TEXT NOT NULL,
    
    FOREIGN KEY('frame_name') REFERENCES t_frame_definition(name)  ON DELETE CASCADE
    FOREIGN KEY('parameter_name') REFERENCES t_tm_parameter(name)
);




-- It relates together frames and comm layers
DROP TABLE  IF EXISTS "t_frame_layer";

