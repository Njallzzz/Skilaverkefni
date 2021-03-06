CREATE TABLE main.computers (
	id  INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL DEFAULT 1,
	name  TEXT NOT NULL,
	creation  TEXT NOT NULL,
	type TEXT NOT NULL,
	constructed INTEGER NOT NULL
);

CREATE TABLE main.people (
	id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL DEFAULT 1,
	name  TEXT NOT NULL,
	gender INTEGER NOT NULL,
	birth TEXT NOT NULL,
	death TEXT DEFAULT NULL
);

CREATE TABLE main.relation (
	id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL DEFAULT 1,
	person INTEGER NOT NULL,
	computer INTEGER NOT NULL
);

DROP TABLE main.computers;
DROP TABLE main.people;
DROP TABLE main.relation;