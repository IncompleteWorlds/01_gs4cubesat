--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--

-- The script will remove all the data from the tables



DELETE FROM t_role;

INSERT INTO t_role VALUES (1, "Read only",     "Users will not be able to modify any data");
INSERT INTO t_role VALUES (2, "Operator",      "Users will able to modify some data. Data required for operating the mission");
INSERT INTO t_role VALUES (3, "Administrator", "Users will have full access. They will be able to modify any data");




DELETE FROM t_app_function;

INSERT INTO t_app_function VALUES(1, "Function 1", "Description of function 1");
INSERT INTO t_app_function VALUES(2, "Function 2", "Description of function 2");
INSERT INTO t_app_function VALUES(3, "Function 3", "Description of function 3");
INSERT INTO t_app_function VALUES(4, "Function 4", "Description of function 4");
INSERT INTO t_app_function VALUES(5, "Function 5", "Description of function 5");




DELETE FROM t_role_function;

INSERT INTO t_role_function VALUES(1, 1);
INSERT INTO t_role_function VALUES(1, 2);

INSERT INTO t_role_function VALUES(2, 1);
INSERT INTO t_role_function VALUES(2, 2);
INSERT INTO t_role_function VALUES(2, 3);
INSERT INTO t_role_function VALUES(2, 4);

-- Role 3 entries are not needed. Administrator will have full access




-- User data needs a mission to be created before hand. Otherwise,
-- database will be in an inconsistent state
DELETE FROM t_user;

INSERT INTO t_user VALUES (1, "user01", "user01", "User 01", "Last name", 1, 2);
INSERT INTO t_user VALUES (2, "userro", "userro", "Read only user", "Last name", 1, 1);
INSERT INTO t_user VALUES (3, "admin", "nopwd01", "Administrator", "Last name", 1, 3);
