CREATE USER 'training'@'localhost' IDENTIFIED BY '12345';
GRANT ALL ON training.* TO 'training'@'localhost';
FLUSH PRIVILEGES;

CREATE USER 'training'@'%' IDENTIFIED BY '12345';
GRANT ALL ON training.* TO 'training'@'%';
FLUSH PRIVILEGES;

select Host,User from mysql.user;
