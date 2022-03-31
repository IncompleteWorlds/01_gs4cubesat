--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2021 Incomplete Worlds
--
-- Taylor for MariaDB/MySQL
--

USE common_db;

DROP TABLE IF EXISTS  t_ground_station;

CREATE TABLE t_ground_station (
    identifier       INTEGER PRIMARY KEY AUTO_INCREMENT,
    name             VARCHAR(40) NOT NULL,
    description      VARCHAR(80),
    code             VARCHAR(10) NOT NULL,
    owner            VARCHAR(40),
    latitude         DOUBLE NOT NULL,
    longitude        DOUBLE NOT NULL,
    altitude         DOUBLE NOT NULL,
    connection_type  INTEGER,
    url              VARCHAR(100),
    port             INTEGER,
    com_port         VARCHAR(20),
    speed            INTEGER,
    parity           BOOLEAN,
    control_bits     INTEGER
);
