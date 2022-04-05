--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--

DROP TABLE IF EXISTS  't_ground_station';

CREATE TABLE "t_ground_station" (
    `identifier`       INTEGER PRIMARY KEY AUTOINCREMENT,
    `name`             TEXT NOT NULL,
    `description`      TEXT,
    `code`             TEXT NOT NULL,
    `owner`            TEXT,
    `latitude`         DOUBLE NOT NULL,
    `longitude`        DOUBLE NOT NULL,
    `altitude`         DOUBLE NOT NULL,
    `connection_type`  INTEGER,
    `url`              TEXT,
    `port`             INTEGER,
    `com_port`         TEXT,
    `speed`            INTEGER,
    `parity`           BOOLEAN,
    `control_bits`     INTEGER
);
