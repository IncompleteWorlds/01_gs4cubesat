--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--

-- The script will remove all the data from the tables

DELETE FROM t_configuration_parameters;

INSERT INTO t_configuration_parameters VALUES ( 1, 'current_mission', '1', '', '');


