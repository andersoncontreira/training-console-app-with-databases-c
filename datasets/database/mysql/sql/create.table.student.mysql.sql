create TABLE IF NOT EXISTS student (
id INTEGER PRIMARY KEY AUTO_INCREMENT,
firstname VARCHAR(30) NOT NULL,
lastname VARCHAR(255) NOT NULL,
age INTEGER,
deleted TINYINT NOT NULL DEFAULT 0,
created_at timestamp NULL DEFAULT CURRENT_TIMESTAMP,
updated_at timestamp NULL,
deleted_at timestamp NULL
);

