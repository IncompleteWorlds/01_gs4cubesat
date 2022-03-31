--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--


-- Users, Roles & Functions definitions
-- ##########################################

-- Users of a Mission
DROP TABLE  IF EXISTS "t_user";

CREATE TABLE "t_user" (
    'identifier'     INTEGER PRIMARY KEY AUTOINCREMENT,

    -- Login details
    'user_name'      TEXT NOT NULL UNIQUE,
    'password'       TEXT NOT NUll,

    -- Person details
    'first_name'     TEXT NOT NULL,
    'last_name'      TEXT NOT NULL,

    'email_address'  TEXT NOT NULL,

    -- Mission user is working on
    -- Only for Mission related roles
    'mission_name',
    'role_id'        INTEGER NOT NULL,

    FOREIGN KEY('mission_name') REFERENCES t_mission(name),
    FOREIGN KEY('role_id') REFERENCES t_role(identifier)
);



DROP TABLE  IF EXISTS "t_role";

--  0 = Administrator 
--  1 = Normal user
--  2 = Read Only
--
--  10 = Mission Administrator 
--  11 = Mission Operator
--  12 = Mission Read Only
--
CREATE TABLE "t_role" (
    'identifier'    INTEGER PRIMARY KEY AUTOINCREMENT,

    'name'  TEXT NOT NULL,
    'description'  TEXT
);


-- It identifies a function of an application
DROP TABLE  IF EXISTS "t_app_function";

CREATE TABLE "t_app_function" (
    'identifier'    INTEGER PRIMARY KEY AUTOINCREMENT,

    'name'  TEXT NOT NULL,
    'description'  TEXT,
    
    'application_id'       INTEGER NOT NULL,

    FOREIGN KEY('application_id') REFERENCES t_application(identifier)
);


-- It identifies an application. I.e. MCS, FDS, Tools, etc.
DROP TABLE  IF EXISTS "t_application";

CREATE TABLE "t_application" (
    'identifier'    INTEGER PRIMARY KEY AUTOINCREMENT,

    'name'  TEXT NOT NULL,
    'description'  TEXT
);


-- It describes application functions of a role
DROP TABLE  IF EXISTS "t_role_function";

CREATE TABLE "t_role_function" (
    'role_id'       INTEGER NOT NULL,
    'function_id'   INTEGER NOT NULL,

    PRIMARY KEY(role_id, function_id),

    FOREIGN KEY('role_id') REFERENCES t_role(identifier),
    FOREIGN KEY('function_id') REFERENCES t_app_function(identifier)
);
