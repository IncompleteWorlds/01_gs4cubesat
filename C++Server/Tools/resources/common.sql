--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--


-- Common and general definitions
-- ##########################################

DROP TABLE  IF EXISTS "t_configuration_parameters";

CREATE TABLE "t_configuration_parameters" (
    'identifier'    INTEGER PRIMARY KEY AUTOINCREMENT,

    'name'          TEXT NOT NULL UNIQUE,
    'description'   TEXT,
    'value'         TEXT NOT NUll,
    'type'          INT NOT NULL,

    -- Owner of the parameter. It can be an user, mission, system, etc.
    'user_id'       INTEGER,
    'misison_name'  TEXT,
    'layer_name'    TEXT
);

