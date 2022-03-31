Readme MariaDb

root/MariadbPwd0$


Create MariaDb users
-------------------------------

Update root priveleges
sql>  GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
sql> FLUSH PRIVILEGES;
sql > show grants;
sql> SHOW GRANTS FOR 'user1'@localhost;


sql>  CREATE DATABASE fds_db  CHARACTER SET UTF8;
sql>  CREATE DATABASE common_db   CHARACTER SET UTF8;


-- CREATE USER 'fdsuserdb'@'localhost' IDENTIFIED BY 'FdsPwd99$';
-- hash = *7AFF22522797A37994184C15229DDF844BFE6308
sql> CREATE USER 'fdsuserdb'@'localhost' IDENTIFIED BY 'FdsPwd99$';
sql> GRANT SELECT, INSERT, UPDATE, DELETE ON fds_db.* TO 'fdsuserdb'@'localhost';
sql> GRANT CREATE, ALTER, DROP ON fds_db.* TO 'fdsuserdb'@'localhost';


-- select password('CommonPwd99$');
-- CREATE USER 'commonuserdb'@'localhost' IDENTIFIED BY 'CommonPwd99$';
-- *11296DACD0EEF60631635EB1D455E56C0D4BAE41
-- hash = *11296DACD0EEF60631635EB1D455E56C0D4BAE41
sql> CREATE USER 'commonuserdb'@'localhost' IDENTIFIED BY 'CommonPwd99$';
sql> GRANT SELECT, INSERT, UPDATE, DELETE ON common_db.* TO 'commonuserdb'@'localhost';
sql> GRANT CREATE, ALTER, DROP ON common_db.* TO 'commonuserdb'@'localhost';

sql>   SELECT User FROM mysql.user;



-- Remove user
-- DROP USER 'user1'@localhost;

-- Update password
sql> set password for 'fdsuserdb'@'localhost' = password('FdsPwd99$');



CREATE TABLES
-------------------------------

sql> mysql --user=commonuserdb --password=CommonPwd99$ common_db    < users.sql   > users_output.txt




