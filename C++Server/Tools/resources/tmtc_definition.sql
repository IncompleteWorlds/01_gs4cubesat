--
-- CubeGS
--   An online Ground Segment for Cubesats and Small Sats
--   (c) 2017 Incomplete Worlds
--
--


-- TC & TM Database definitions
-- ##########################################




-- TM Definition
-- Also a TM parameter of a TM frame
DROP TABLE  IF EXISTS "t_tm_parameter";

CREATE TABLE "t_tm_parameter" (
    'name'           TEXT PRIMARY KEY,

    'display_name'   TEXT,
    'description'    TEXT,

    -- Node Id
    -- A mission could not use Nodes
    'node_id'        INTEGER,

    -- Channel Id or TM point within the subsystem or node
    -- A mission could not use Channels
    'channel_id'     INTEGER,
    
    'length_bits'    INTEGER NOT NULL,

    -- Compliant with PUS
    -- None - 0, Boolean - 1, Enumerated - 2, Unsigned Integer - 3, Signed Integer - 4
    -- Real - 5, Bit-String - 6, Octet-String - 7, Character-String (ASCII) - 8
    -- Absolute Time - 9, Relative Time - 10, Deduced - 11
    -- New values (not PUS compliant):
    -- 12 - Fixed String (specify size in bits column)
    -- 13 - Null Terminated String (ends with 0x0)
    -- 14 - Prepended Size String
    -- 15 - Byte stream
    --
    -- Alias 'raw_type'
    'type'            INTEGER NOT NULL,

    -- 0 - Int8, 1 - Int16, 2 - Int32, 3 - Int64,
    -- 4 - UInt8, 5 - Uint16, 6 - Uint32, 7 - UInt64
    'subtype'         INTEGER NOT NULL,

    --
    -- 0 - uint
    -- 1 - uint64
    -- 2 - int
    -- 3 - int64
    -- 4 - enumerated
    -- 5 - float
    -- 6 - double
    -- 7 - boolean
    -- 8 - string
    -- 9 - binary
    'eng_type'         INTEGER NOT NULL,

    -- Free text
    'units'            TEXT NOT NULL,
    
    -- Prepend size of String or Binary streams
    'prepend_size'     INTEGER NOT NULL,
    
    -- Character. String terminator byte
    'string_terminator'   TEXT,

    -- 1 - True, 0 - False
    'little_endian'     INTEGER NOT NULL,

    -- Calibration function
    'function_name'    TEXT NOT NULL,
    

    -- Type of TM;
    -- 0 - None, 1 - Current, 2 - Voltage, 3 - Power, 4 - Temperature
    --'tm_type'	INTEGER,

    -- None - 0, Analogue - 1, Digital - 2, Cmd - 3
    --'magnitude_type'	INTEGER NOT NULL,

    -- Field that contains the length of this field
    'length_field_id'   INTEGER,



    -- 'default_value'     TEXT,


    -- RADIX_NONE = 0, RADIX_DECIMAL = 1, RADIX_HEXADECIMAL = 2
    'radix'             INTEGER NOT NULL,


    -- Raw or engineering value. Raw - true, Engineering - false
    --'raw_flag'  INTEGER,


    -- true - 1, false - 0
    --'crc_flag'	INTEGER NOT NULL,
    --'crc_algorithm'	TEXT,

    -- Subsystem identifier
    'subsystem_name'  TEXT NOT NULL,

    FOREIGN KEY('subsystem_name') REFERENCES t_subsystem(name) ON DELETE CASCADE,

    FOREIGN KEY('function_name') REFERENCES t_function (name),
    
    -- Use is TBD
    FOREIGN KEY('node_id') REFERENCES t_node (identifier)  ON DELETE CASCADE
);



-- Derived TM Definition
-- An algorithm will derived this parameter
DROP TABLE  IF EXISTS "t_tm_derived_parameter";

CREATE TABLE "t_tm_derived_parameter" (
    'name'           TEXT PRIMARY KEY,

    'display_name'   TEXT,
    'description'    TEXT,

    'length_bits'    INTEGER NOT NULL,
    
    -- Prepend size of String or Binary streams
    'prepend_size'     INTEGER NOT NULL,
    
    -- Character. String terminator byte
    'string_terminator'   TEXT,

    -- 1 - True, 0 - False
    'little_endian'     INTEGER NOT NULL,

    -- Compliant with PUS
    -- None - 0, Boolean - 1, Enumerated - 2, Unsigned Integer - 3, Signed Integer - 4
    -- Real - 5, Bit-String - 6, Octet-String - 7, Character-String (ASCII) - 8
    -- Absolute Time - 9, Relative Time - 10, Deduced - 11
    -- New values (not PUS compliant):
    -- 12 - Fixed String (specify size in bits column)
    -- 13 - Null Terminated String (ends with 0x0)
    -- 14 - Prepended Size String
    -- 15 - Byte stream
    --
    -- Alias 'raw_type'
    'type'   INTEGER NOT NULL,

    -- 0 - Int8, 1 - Int16, 2 - Int32, 3 - Int64,
    -- 4 - UInt8, 5 - Uint16, 6 - Uint32, 7 - UInt64
    'subtype'    INTEGER NOT NULL,

    --
    -- 0 - uint
    -- 1 - uint64
    -- 2 - int
    -- 3 - int64
    -- 4 - enumerated
    -- 5 - float
    -- 6 - double
    -- 7 - boolean
    -- 8 - string
    -- 9 - binary
    'eng_type'         INTEGER NOT NULL,

    -- Calibration function
    'function_name'    TEXT  NOT NULL,

    -- Subsystem identifier
    'subsystem_name'   TEXT NOT NULL,

    FOREIGN KEY('function_name') REFERENCES t_function (name),

    FOREIGN KEY('subsystem_name') REFERENCES t_subsystem(name) ON DELETE CASCADE
);


-- It defines a Calibration function of a TM parameter
DROP TABLE  IF EXISTS "t_function";

CREATE TABLE 't_function' (
    'name'              TEXT PRIMARY KEY,
    'description'       TEXT NOT NULL,
    
    -- 0 - Int2Int, 1 - Int2Text, 2 - Int2Float
    -- 3 - Enumeration
    -- 4 - Polynomial
    -- 5 - Spline
    'calibration_type'  INTEGER NOT NULL,
    
    'num_values'        INTEGER NOT NULL,    
    
    -- Subsystem identifier
    'subsystem_name'    TEXT NOT NULL,

    FOREIGN KEY('subsystem_name') REFERENCES t_subsystem(name) ON DELETE CASCADE
);


-- It defines a Calibration coefficient of a function
DROP TABLE  IF EXISTS "t_function_value";

CREATE TABLE "t_function_value" (
    'function_name'    TEXT PRIMARY KEY,
    
    -- ???? TBC
    'key'              TEXT NOT NULL,
    
    -- "for enumeration list the id (integer value)
    --  for polynomials list the coefficients in order from least important on top to most important on bottom   
    -- for spline the x value"
    'x'                REAL NOT NULL,
    
    -- "for enumeration list the values corresponding to the id in the previous column
    -- for spline the y value"
    'y'                REAL NOT NULL,
    -- I.e. text assigned to a X value in digital values
    'y_text'           TEXT NOT NULL,

    FOREIGN KEY('function_name') REFERENCES t_function(name)  ON DELETE CASCADE
);


-- It contains user defined algorithms that will create derived parameters based on other parameters
DROP TABLE  IF EXISTS "t_algorithm";

CREATE TABLE "t_algorithm" (
    'name'       TEXT PRIMARY KEY,

    -- Values; python, java, javascript
    'language'   TEXT NOT NULL,
    
    -- The algorithm itself
    'text'       TEXT NOT NULL,
    
    -- Values: 
    --     3 - OnParameterUpdate(p1,p2, …) - the algorithm triggers when one of the specified parameters updates
    --     2 - OnInputParameterUpdate – this is same as above for all input parameters
    --     1 - OnPeriodicRate(<fireRateInMs>) - the algorithm triggers periodically
    --     0 - none – the algorithm doesn't trigger automatically but can be called upon 
    --            from other parts of the system (like the command verifier)
    --            This is the default
    'trigger'   INTEGER NOT NULL,
    
    -- Subsystem identifier
    'subsystem_name'    TEXT NOT NULL,

    FOREIGN KEY('subsystem_name') REFERENCES t_subsystem(name) ON DELETE CASCADE
);


-- It defines a parameter used in an Algorithm
DROP TABLE  IF EXISTS "t_algorithm_parameter";

CREATE TABLE "t_algorithm_parameter" (
    'algorithm_name'  TEXT PRIMARY KEY,
    
    -- 0 - input, 1 - output
    'in_out'          INTEGER NOT NULL,
    
    'parameter_name'  TEXT NOT NULL,
    
    -- This column is applicable for each in parameter. 
    -- It is a number indicating which instance (from the past) of the parameter shall be used as input. 
    -- 0 - means latest value, 
    -- 1 - means last but one value, etc.
    'parameter_value'       INTEGER NOT NULL,
    
    'name_used_algorithm'   TEXT NOT NULL,
    
    -- "This column is applicable for each in parameter and can have the following values:
    --   M - mandatory  -the algorithm will not trigger unless a value is set for this input parameter."
    'flag'            TEXT NOT NULL,
    
    FOREIGN KEY('parameter_name') REFERENCES t_tm_parameter(name),
    FOREIGN KEY('algorithm_name') REFERENCES t_algorithm(name)  ON DELETE CASCADE

);


-- Alarms related to a parameter
DROP TABLE  IF EXISTS "t_alarm";

CREATE TABLE "t_alarm" (
    'identifier'   INTEGER PRIMARY KEY AUTOINCREMENT,
    
    -- Reference to a parameter. See the “Rules for parameter/container reference lookup” above to understand how this is resolved.
    'parameter_name'  TEXT NOT NULL,
    
    FOREIGN KEY('parameter_name') REFERENCES t_tm_parameter(name)
);


-- Alarms related to a parameter
--  Or, one or more conditions (separated by ';') that must all apply for the context to be in effect.
DROP TABLE  IF EXISTS "t_alarm_condition";

CREATE TABLE "t_alarm_condition" (
    'alarm_id'   INTEGER PRIMARY KEY AUTOINCREMENT,
    
    -- "Context under which the alarms apply:
    -- - Leave blank for defining the default alarms of this param (conventionally at the beginning)
    -- - Or, one or more conditions (separated by ';') that must all apply for the context to be in effect.
    -- Contextual alarms are evaluated from top to bottom, until a match is found
    'context'  TEXT NOT NULL,

    -- When alarms for this context should be reported.
    -- One of:
    -- 0 - OnValueChange
    -- 1 - OnSeverityChange   (this is the default)
    'report'   INTEGER NOT NULL,

    -- Number of successive instances that meet any of the alarm conditions under this context before the alarm is reported.
    -- default is 1
    'min_violations'   INTEGER NOT NULL,
    
    -- 0 - low
    -- 1 - high
    -- 2 - state
    'watchTriggerType' INTEGER NOT NULL,
    
    --  - number for low/high trigger
    --  - enum value for state trigger type
    'watchTriggerValue'  TEXT NOT NULL,
    
    'warningTriggerType' INTEGER NOT NULL,
    'warningTriggerValue'   TEXT NOT NULL,
    
    'distressTriggerType' INTEGER NOT NULL,
    'distressTriggerValue'  TEXT NOT NULL,
    
    'criticalTriggerType' INTEGER NOT NULL,
    'criticalTriggerValue'  TEXT NOT NULL,
    
    'severeTriggerType' INTEGER NOT NULL,
    'severeTriggerValue'  TEXT NOT NULL,
        
    FOREIGN KEY('alarm_id') REFERENCES t_alarm(identifier)  ON DELETE CASCADE
);




-- TC Definition
-- Also a TC parameter of a TC frame
-- Alias 'Command'
DROP TABLE  IF EXISTS "t_tc_parameter";

CREATE TABLE "t_tc_parameter" (
    'name'            TEXT PRIMARY KEY,
    
    'display_name'    TEXT NOT NULL,
    'description'     TEXT NOT NULL,

    -- parent reference
    'parent'          TEXT,
    
    -- Node Id
    -- A mission could not use Nodes
    'node_id'        INTEGER,

    -- Channel Id or TM point within the subsystem or node
    -- A mission could not use Channels
    'channel_id'     INTEGER,
    
    'length_bits'    INTEGER NOT NULL,
    
    -- 0 = false,  1 = true
    'abstract_flag'   INTEGER NOT NULL,
    
        -- Subsystem identifier
    'subsystem_name'  TEXT NOT NULL,

    FOREIGN KEY('subsystem_name') REFERENCES t_subsystem(name) ON DELETE CASCADE
);

-- Arguments assignement for this TC
DROP TABLE  IF EXISTS "t_tc_parameter_arg_assigment";

CREATE TABLE "t_tc_parameter_arg_assigment" (
    'tc_name'    TEXT PRIMARY KEY,
    
    'arg_name'   TEXT NOT NULL,
    'arg_value'  TEXT NOT NULL,
    
    FOREIGN KEY('tc_name') REFERENCES t_tc_parameter(name)  ON DELETE CASCADE
);


-- Arguments of a TC
DROP TABLE  IF EXISTS "t_tc_parameter_argument";

CREATE TABLE "t_tc_parameter_argument" (
    'name'       TEXT PRIMARY KEY,
    
    'description'    TEXT,

    -- TC this argument is related to
    'tc_name'    TEXT NOT NULL,
    
    -- Defautl value is 0
    'relpos'         INTEGER  NOT NULL,
    
    'length_bits'    INTEGER NOT NULL,

    -- Compliant with PUS
    -- None - 0, Boolean - 1, Enumerated - 2, Unsigned Integer - 3, Signed Integer - 4
    -- Real - 5, Bit-String - 6, Octet-String - 7, Character-String (ASCII) - 8
    -- Absolute Time - 9, Relative Time - 10, Deduced - 11
    -- New values (not PUS compliant):
    -- 12 - Fixed String (specify size in bits column)
    -- 13 - Null Terminated String (ends with 0x0)
    -- 14 - Prepended Size String
    -- 15 - Byte stream
    --
    -- Alias 'raw_type'
    'type'            INTEGER NOT NULL,

    -- 0 - Int8, 1 - Int16, 2 - Int32, 3 - Int64,
    -- 4 - UInt8, 5 - Uint16, 6 - Uint32, 7 - UInt64
    'subtype'         INTEGER NOT NULL,

    --
    -- 0 - uint
    -- 1 - uint64
    -- 2 - int
    -- 3 - int64
    -- 4 - enumerated
    -- 5 - float
    -- 6 - double
    -- 7 - boolean
    -- 8 - string
    -- 9 - binary
    'eng_type'         INTEGER NOT NULL,
    
    -- Free text
    'units'            TEXT NOT NULL,

    -- Prepend size of String or Binary streams
    'prepend_size'     INTEGER NOT NULL,
    
    -- Character. String terminator byte
    'string_terminator'   TEXT,

    -- 1 - True, 0 - False
    'little_endian'     INTEGER NOT NULL,

    -- Calibration function
    'function_name'    TEXT NOT NULL,
    
    'default_value'    TEXT NOT NULL,
    
    -- The lowest value (inclusive) that the argument may have.
    'range_low'   TEXT,
    
    -- The highest value (inclusive) that the argument may have
    'range_high'   TEXT,

    FOREIGN KEY('function_name') REFERENCES t_function (name),
        
    FOREIGN KEY('tc_name') REFERENCES t_tc_parameter(name)  ON DELETE CASCADE
);


-- Options for transmiting a TC
DROP TABLE  IF EXISTS "t_tc_parameter_options";

CREATE TABLE "t_tc_parameter_options" (
    -- TC this options are related to
    'tc_name'    TEXT PRIMARY KEY,

    -- Significance level of TC
    -- one of:
    -- 0 - none
    -- 1 - watch
    -- 2 - warning
    -- 3 - distress
    -- 4 - critical
    -- 5 - severe
    'significance'   INTEGER NOT NULL,
    
    'significance_reason'  TEXT,
    
    FOREIGN KEY('tc_name') REFERENCES t_tc_parameter(name)  ON DELETE CASCADE
);


-- Conditions that has to be met for the command to be sent.  Currently conditions can only be put 
-- on parameters and cannot take into account argument of the commands (e.g. one cannot allow a command to 
-- be sent only if an argument has a certain value). 
-- There are currently three forms supported:
-- Simple condition: 
--    Parameter==value
-- Condition list:
--        Parameter==value;Parameter2==value2 - all conditions must be true
-- Boolean condition:
--     op(epx1;exp2;...;expn)
--     - op is '&' (AND) or '|' (OR)
--     - expi is a boolean expression or a simple condition
-- Constrains can be specified on multiple lines. All of them have to be met for the command to be allowed for transmission.

-- Options for transmiting a TC
DROP TABLE  IF EXISTS "t_tc_parameter_opt_constraints";

CREATE TABLE "t_tc_parameter_opt_constraints" (
    -- TC this options are related to
    'tc_name'    TEXT PRIMARY KEY,

    'constraint'  TEXT NOT NULL,

    -- The timeout of the constraint. A command stays in the queue for that many milliseconds. 
    -- If the constraint is not met, the command is rejected.
    -- 0 means that the command is rejected even before being added to the queue, if the constraint is not met.
    -- Default value is 0
    'timeout'     INTEGER NOT NULL,

    FOREIGN KEY('tc_name') REFERENCES t_tc_parameter(name)  ON DELETE CASCADE
);


-- The Command verification sheets defines how a command shall be verified once it has been sent t_tc_pa
-- for execution. The transmission/execution of a command usual goes through multiple stages. 
-- Each of them can be defined on one line.
-- Each verifier runs within a defined time window which can be relative to the release of the command 
-- or to the completion of the previous verifier. The verifiers can either return one of  two outputs 
-- OK = Success , 
-- NOK=Fail or they can timeout meaning that the condition could not be verified either true or false within 
-- the defined time interval. For each verifier it has to be defined what happens for each of the three outputs.


DROP TABLE  IF EXISTS "t_tc_parameter_verifier";

CREATE TABLE "t_tc_parameter_verifier" (
    -- TC this options are related to
    'tc_name'    TEXT PRIMARY KEY,

    -- Any stage is accepted but XTCE defines the following ones:
    -- 0 - TransferredToRange
    -- 1 - SentFromRange
    -- 2 - Received
    -- 3 - Accepted
    -- 4 - Queued
    -- 5 - Execution
    -- 6 - Complete
    -- 7 - Failed
    -- If special actions (like declaring the command as completed) are required for Complete or Failed, 
    -- they have to be configured in OnSuccess/OnFail/OnTimeout columns. By default command history events 
    -- with the name Verification_<stage> are generated.
    'tc_stage'     INTEGER NOT NULL,
    
    -- Supported types are:
    -- 0 - container – the command is considered verified when the container is received. 
    --     Note that this cannot generate a Fail (NOK) condition - it's either OK if the container is received 
    --     in the timewindow or timeout if the container is not received.
    -- 1 - algorithm – the result of the algorithm run is used as the output of the verifier. If the algorithm 
    --     is not run (because it gets no inputs) or returns null, then the timeout condition applies
    'verifier_type'  INTEGER NOT NULL,
    
    
    -- Depending on the type: 
    -- - container: is the name of the container
    -- - algorithm: is the name of the algorithm"    
    'verifier_text'   TEXT NOT NULL,
    
    -- Start time of the window in milliseconds
    'start_time_check_window'   INTEGER NOT NULL,

    -- Stop time of the window in milliseconds
    'stop_time_check_window'   INTEGER NOT NULL,

    -- 0 - LastVerifier (default) – the start,stop in the window definition are relative to the end of the 
    --    previous verifier. If there is no previous verifier, the start,stop are relative to the command release time. 
    --    If the previous verifier ends with timeout, this verifier will also timeout without checking anything.
    -- 1 CommandRelease - the start,stop in the window definition are relative to the command release
    'check_window'   INTEGER NOT NULL,
    
    -- Defines what happens when the verification returns true. It has to be one of:
    -- 0 - none (default) – only a Verification_stage event is generated without an effect on the final execution status of the command.
    -- 1 - SUCCESS: command considered completed successful (CommandComplete event is generated)
    -- 2 - FAIL:  CommandFailed event is generated
    'on_success'     INTEGER NOT NULL,
    
    -- Same like OnSuccess but the event is generated in case the verifier returns false.
    'on_fail'        INTEGER NOT NULL,
    
    -- Same as OnSuccess but the event is generated in case the verifier times out.
    'on_timeout'     INTEGER NOT NULL,

    FOREIGN KEY('tc_name') REFERENCES t_tc_parameter(name)  ON DELETE CASCADE
);















-- It relates a TM parameter with an Action
-- DROP TABLE  IF EXISTS "t_tm_definition_action";

-- CREATE TABLE "t_tm_definition_action" (
--     'parameter_id'	INTEGER,
--     'action_id'	INTEGER,

--     PRIMARY KEY(parameter_id,action_id),

--     FOREIGN KEY('parameter_id') REFERENCES t_tm_parameter ( identifier ),
--     FOREIGN KEY('action_id') REFERENCES t_action(identifier)
-- );


-- List of Actions. I.e. Send an email, write a log message
-- DROP TABLE  IF EXISTS "t_action";

-- CREATE TABLE "t_action" (
--     'identifier'      INTEGER PRIMARY KEY AUTOINCREMENT,

--     -- 0- None, 1 - Email, 2 - Log
--     'type'            INTEGER NOT NULL,

--     -- Warning, Error (TBC)
--     'category'        INTEGER NOT NULL,
--     -- Email address
--     'address'         TEXT NOT NULL,

--     'parameter_id'	INTEGER NOT NULL,

--     FOREIGN KEY('parameter_id') REFERENCES t_tm_parameter(identifier)
-- );




