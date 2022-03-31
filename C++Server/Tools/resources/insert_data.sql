--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--

-- The script will remove all the data from the tables


DELETE FROM "t_mission_default_comms_layer";

INSERT INTO "t_mission_default_comms_layer" VALUES ('KISS',  'KISS layer');
INSERT INTO "t_mission_default_comms_layer" VALUES ('AX.25', 'AX.25 layer');
INSERT INTO "t_mission_default_comms_layer" VALUES ('CSP',   'CSP Layer');
INSERT INTO "t_mission_default_comms_layer" VALUES ('HDLC',  'HDLC layer');

DELETE FROM t_mission;

INSERT INTO "t_mission" VALUES ( 1, 'mi01', 'First test mission', 'uk', 'Incomplete Worlds', '2017-04-26 18:11:00.000' );



DELETE FROM t_satellite;

INSERT INTO "t_satellite" VALUES ( 1, "sa01", "Description first satellite", "sa01", "2017-06-22 00:00:00.000", 1 );
INSERT INTO "t_satellite" VALUES ( 2, "sa02", "Description second satellite", "sa02", "2017-06-22 00:00:00.000", 1 );



DELETE FROM t_subsystem;

INSERT INTO "t_subsystem" VALUES ( 1, "Power", "Power subsystem", 1 );
INSERT INTO "t_subsystem" VALUES ( 2, "AOCS",  "AOCS subsystem", 1 );
INSERT INTO "t_subsystem" VALUES ( 3, "OBDH",  "Onboard computer subsystem", 1 );
INSERT INTO "t_subsystem" VALUES ( 4, "TX",    "Transmitter subsystem", 1 );
INSERT INTO "t_subsystem" VALUES ( 5, "RX",    "Receiver subsystem", 1 );

INSERT INTO "t_subsystem" VALUES ( 6, "Power", "Power subsystem", 2 );
INSERT INTO "t_subsystem" VALUES ( 7, "AOCS",  "AOCS subsystem", 2 );
INSERT INTO "t_subsystem" VALUES ( 8, "OBDH",  "Onboard computer subsystem", 2 );
INSERT INTO "t_subsystem" VALUES ( 9, "TX",    "Transmitter subsystem", 3 );
INSERT INTO "t_subsystem" VALUES ( 10, "RX",    "Receiver subsystem", 2 );



DELETE FROM t_node;

INSERT INTO "t_node" VALUES ( 1, "Power1", "First node of power", 1);
INSERT INTO "t_node" VALUES ( 2, "Power2", "Second node of power", 1);

