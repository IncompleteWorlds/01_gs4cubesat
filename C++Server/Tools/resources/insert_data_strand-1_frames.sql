--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
-- This script will insert the initial data of Strand-1 mission
-- Big endian
-- MSB first



-- ========================================================================
-- ==   Layer:  (2, "hdlc_upd",  "Updated HDLC frame types", 1, 3); 
-- ========================================================================

DELETE FROM t_frame_definition;
DELETE FROM t_tc_parameter;
DELETE FROM t_tc_definition_parameter;

DELETE FROM t_tm_parameter;
DELETE FROM t_tm_definition_parameter;




-- ========================================================================
-- ==   Layer:  (3, "obc_layer",  "OBC Layer", 2, 3); 
-- ========================================================================

INSERT INTO t_frame_definition ("identifier", "parent_identifier", "name", "description", "hktm_flag", "length_bytes", "start_delimiter", 	"end_delimiter", "identification_value", "identification_field", "layer_id")
VALUES (20,  0, "modem beacom frame", "MoAX.25 Unnumbered Information frame", 2, 0, 0, 0, 0, 20, 20, 0, 0, 0,  3);





-- ========================================================================
-- ==   Layer:  (4, "beacon_layer",  "Beacon Layer", 3, 3);
-- ========================================================================







-- ========================================================================
-- ==   AX.25
-- ========================================================================

-- Two flags; at beginning and at end
INSERT INTO t_frame_definition VALUES (20,  0, "ax25_ui_frame", "AX.25 Unnumbered Information frame", 2, 0, 0, 0, 0, 20, 20, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (21, 20, "transfer_frame_header", "Transfer Frame Header", 2, 16, 0, 0, 0, 0, 0, 0, 0, 0);

INSERT INTO t_frame_definition VALUES (22, 20, "destination_address", "Destination address", 2, 7, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (23, 20, "source_address", "Source address", 2, 7, 0, 0, 0, 0, 0, 0, 0, 0);


-- AX.25 Transfer Frame Header
INSERT INTO t_tm_parameter VALUES (20, 0, 0, "flag", "AX25 flag", "AX25 flag", 0, 8, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (21, 0, 0, "control_bits", "Control Bits", "Control Bits", 0, 8, 1, 2,   2, "", 0, 0, 0, "");

Protocol Identifier

-- Information Field

-- Frame Check Sequence


-- ========================================================================
-- ==  CCSDS TELEMETRY
-- ========================================================================

INSERT INTO t_frame_definition VALUES (1, 0, "ccsds_telecommand", "CCSDS Telecommand frame including header and data", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (2, 1, "ccsds_tc_packet_header", "CCSDS Telecommand. Packet Header", 1, 6, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (3, 1, "ccsds_tc_packet_data_field", "CCSDS Telecommand. Packet Data Field", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (4, 3, "ccsds_tc_data_field_header", "CCSDS Telecommand. Data Field Header", 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);



-- Definition of the parameters that composes the TC frame

--  CCSDS Packet Header
INSERT INTO t_tc_parameter VALUES (1, "version_number", "Version", "Version number", 0, 3, 1, 2);
INSERT INTO t_tc_parameter VALUES (2, "type", "Type", "Type", 0, 1, 1, 2);
INSERT INTO t_tc_parameter VALUES (3, "data_field_header", "Data Field Header", "Data Field Header", 0, 1, 1, 2);
INSERT INTO t_tc_parameter VALUES (4, "apid", "APID", "Application identifier", 0, 11, 1, 2);
INSERT INTO t_tc_parameter VALUES (5, "sequence_flag", "Sequence Flag", "Sequence flag", 0, 2, 1, 2);
INSERT INTO t_tc_parameter VALUES (6, "sequence_count", "Sequence count", "Sequence count", 0, 14, 1, 2);
INSERT INTO t_tc_parameter VALUES (7, "packet_length", "Pactket length", "Packet length", 0, 16, 1, 2);

-- TC CCSDS Data Field
--   TC Data Field Header
INSERT INTO t_tc_parameter VALUES (8,  "sec_header_flag", "Sec Header Flag", "Secondary Header Flag", 0, 1, 1, 4);
INSERT INTO t_tc_parameter VALUES (9,  "pus_version_number", "PUS Version number", "PUS Version number", 0, 3, 1, 2);
INSERT INTO t_tc_parameter VALUES (10, "ack", "Ack", "Acknowledgment", 0, 4, 1, 2);
INSERT INTO t_tc_parameter VALUES (11, "service_type", "Service type", "PUS Service type", 0, 8, 1, 2);
INSERT INTO t_tc_parameter VALUES (12, "service_subtype", "Service subtype", "PUS Service subtype", 0, 8, 1, 2);


-- TC  Application Data
INSERT INTO t_tc_parameter VALUES (13, "application_data", "Application data", "Application data", 0, 0, 1, 0);

-- TC  Packet Error Control
INSERT INTO t_tc_parameter VALUES (14, "packet_error_control", "Packet error control", "Packet error control", 0, 16, 1, 2);



-- TC CCSDS Packet Header
INSERT INTO t_tc_definition_parameter VALUES (2, 1, "0");
INSERT INTO t_tc_definition_parameter VALUES (2, 2, "1");
INSERT INTO t_tc_definition_parameter VALUES (2, 3, "1");
INSERT INTO t_tc_definition_parameter VALUES (2, 4, "");
INSERT INTO t_tc_definition_parameter VALUES (2, 5, "3");
INSERT INTO t_tc_definition_parameter VALUES (2, 6, "");
INSERT INTO t_tc_definition_parameter VALUES (2, 7, "");

-- TC CCSDS Data Field
INSERT INTO t_tc_definition_parameter VALUES (3, 13, "");
INSERT INTO t_tc_definition_parameter VALUES (3, 14, "");

-- TC Data Field Header
INSERT INTO t_tc_definition_parameter VALUES (4, 8, "0");
INSERT INTO t_tc_definition_parameter VALUES (4, 9, "1");
INSERT INTO t_tc_definition_parameter VALUES (4, 10, "");
INSERT INTO t_tc_definition_parameter VALUES (4, 11, "");
INSERT INTO t_tc_definition_parameter VALUES (4, 12, "");


-- ========================================================================
-- ==   CCSDS TELEMETRY
-- ========================================================================

INSERT INTO t_frame_definition VALUES (10, 0, "ccsds_telemetry",   "CCSDS Telemetry frame including header and data",   0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (11, 10, "ccsds_tm_packet_header", "CCSDS Telemetry. Packet Header", 0, 6, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (12, 10, "ccsds_tm_packet_data_field", "CCSDS Telemetry. Packet Data Field", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO t_frame_definition VALUES (13, 12, "ccsds_tm_data_field_header", "CCSDS Telemetry. Data Field Header", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);




--  CCSDS Packet Header
INSERT INTO t_tm_parameter VALUES (1, 0, 0, "version_number", "Version", "Version number", 0, 3, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (2, 0, 0, "type", "Type", "Type", 0, 1, 1, 2,    2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (3, 0, 0, "data_field_header", "Data Field Header", "Data Field Header", 0, 1, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (4, 0, 0, "apid", "APID", "Application identifier", 0, 11, 1, 2,    2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (5, 0, 0, "sequence_flag", "Sequence Flag", "Sequence flag", 0, 2, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (6, 0, 0, "sequence_count", "Sequence count", "Sequence count", 0, 14, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (7, 0, 0, "packet_length", "Pactket length", "Packet length", 0, 16, 1, 2,   2, "", 0, 0, 0, "");


-- TM CCSDS Data Field
--   TM Data Field Header
INSERT INTO t_tm_parameter VALUES (8,  0, 0, "spare", "Spare", "Spare", 0, 1, 1, 4,    2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (9,  0, 0, "pus_version_number", "PUS Version number", "PUS Version number", 0, 3, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (10, 0, 0, "spare 1", "Spare 1", "Spare", 0, 4, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (11, 0, 0, "service_type", "Service type", "PUS Service type", 0, 8, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (12, 0, 0, "service_subtype", "Service subtype", "PUS Service subtype", 0, 8, 1, 2,   2, "", 0, 0, 0, "");
INSERT INTO t_tm_parameter VALUES (13, 0, 0, "absolute_time", "Absolute time", "Absolute time", 0, 40, 1, 7,   2, "", 0, 0, 0, "");


-- TM  Application Data
INSERT INTO t_tm_parameter VALUES (14, 0, 0, "source_data", "Source data", "Source data", 0, 0, 1, 0,   0, "", 0, 0, 0, "");

-- TM  Packet Error Control
INSERT INTO t_tm_parameter VALUES (15, 0, 0, "packet_error_control", "Packet error control", "Packet error control", 0, 16, 1, 2,   2, "", 0, 0, 0, "");



-- TM CCSDS Packet Header
INSERT INTO t_tm_definition_parameter VALUES (11, 1, "0");
INSERT INTO t_tm_definition_parameter VALUES (11, 2, "0");
INSERT INTO t_tm_definition_parameter VALUES (11, 3, "1");
INSERT INTO t_tm_definition_parameter VALUES (11, 4, "");
INSERT INTO t_tm_definition_parameter VALUES (11, 5, "3");
INSERT INTO t_tm_definition_parameter VALUES (11, 6, "");
INSERT INTO t_tm_definition_parameter VALUES (11, 7, "");


INSERT INTO t_tm_definition_parameter VALUES (13, 8, "0");
INSERT INTO t_tm_definition_parameter VALUES (13, 9, "1");
INSERT INTO t_tm_definition_parameter VALUES (13, 10, "0");
INSERT INTO t_tm_definition_parameter VALUES (13, 11, "");
INSERT INTO t_tm_definition_parameter VALUES (13, 12, "");
INSERT INTO t_tm_definition_parameter VALUES (13, 13, "");


INSERT INTO t_tm_definition_parameter VALUES (12, 14, "");

INSERT INTO t_tm_definition_parameter VALUES (12, 15, "");



