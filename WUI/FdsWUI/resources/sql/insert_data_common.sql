--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2021 Incomplete Worlds
--
--

-- The script will remove all the data from the tables

# Tell mysql to ignore foreign keys for a little while
SET FOREIGN_KEY_CHECKS = 0;

DELETE FROM t_configuration_parameters;

INSERT INTO t_configuration_parameters VALUES (1, 'current_mission', 'mission description', '1', 0, 0, 'mission1', 'no layer');



DELETE FROM t_role;

INSERT INTO t_role VALUES (1, "Read only",     "Users will not be able to modify any data");
INSERT INTO t_role VALUES (2, "Operator",      "Users will able to modify some data. Data required for operating the mission");
INSERT INTO t_role VALUES (3, "Administrator", "Users will have full access. They will be able to modify any data");
INSERT INTO t_role VALUES (10, "MissionOperator",      "A Mission Operator");
INSERT INTO t_role VALUES (11, "MissionAdministrator", "The Mission Administrator");


-- User data needs a mission to be created before hand. Otherwise,
-- database will be in an inconsistent state
DELETE FROM t_user;

INSERT INTO t_user VALUES (1, "user01", PASSWORD("user01"),  "User 01",        "Last name", "none@domain.com", 2);
INSERT INTO t_user VALUES (2, "userro", PASSWORD("userro"),  "Read only user", "Last name", "none@domain.com", 1);
INSERT INTO t_user VALUES (3, "admin",  PASSWORD("nopwd01"), "Administrator",  "Last name", "none@domain.com", 3);


SET FOREIGN_KEY_CHECKS = 1;

