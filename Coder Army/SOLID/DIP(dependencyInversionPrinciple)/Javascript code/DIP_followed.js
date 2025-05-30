class Database {
  save(data) {
    throw new Error("Method 'save()' must be implemented.");
  }
}

class MySQLDatabase extends Database {
  save(data) {
    console.log(`Insert into db.company.users value ('${data}')`);
  }
}

class MongodbDatabase extends Database {
  save(data) {
    console.log(`Insert into MongodbDatabase value ('${data}')`);
  }
}

class CassandraDatabase extends Database {
  save(data) {
    console.log(`Insert into CassandraDatabase value ('${data}')`);
  }
}

class UserServices {
  constructor(db) {
    this.db = db; // Dependency injection
  }

  storeToDB(user) {
    this.db.save(user);
  }
}

// Usage
const mySQL = new MySQLDatabase();
const mongoDB = new MongodbDatabase();
const cassandraDB = new CassandraDatabase();

const service = new UserServices(mySQL);
service.storeToDB("Kuldeep");


const mongoService = new UserServices(mongoDB);
mongoService.storeToDB("Amit");

const cassandraService = new UserServices(cassandraDB);
cassandraService.storeToDB("Ravi");
