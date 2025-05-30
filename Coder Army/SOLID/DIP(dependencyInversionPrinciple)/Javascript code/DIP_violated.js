class MySql {
  saveToSql(data) {
    console.log(`Insert into users value ('${data}')`);
  }
}

class MongoDB {
  saveToMongodb(data) {
    console.log(`Insert into db.company.users value ('${data}')`);
  }
}

class UserService{
  constructor(){
    this.sqlDB= new MySql() // MySql sqlDB
    this.mongoDB= new MongoDB() // Mongodb= mmongoDB
  }

  storeUserToSQL(user){
    this.sqlDB.saveToSql(user)
  }
  storeUserToMongoDB(user){
    this.mongoDB.saveToMongodb(user)
  }
}

const service= new UserService()
service.storeUserToMongoDB("Ram")
service.storeUserToSQL("shyam")