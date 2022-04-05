--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--

DROP TABLE IF EXISTS 't_raw_frame';

CREATE TABLE `t_raw_frame` (
    `event_time`	INTEGER,
    `data_length`	INTEGER NOT NULL,
    `data`	BLOB NOT NULL,
    PRIMARY KEY(event_time)
);



DROP TABLE IF EXISTS 't_processed_frame';

CREATE TABLE "t_processed_frame" (
    `event_time`	INTEGER,
    `data_length`	INTEGER NOT NULL,
    `data`	BLOB NOT NULL,
    PRIMARY KEY(event_time)
)
