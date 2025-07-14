// A Precondition must be statisfied before a method can be executed.
// Sub classes can weaken the precondition but cannot strengthen it.
// If the subclass makes it stricter, the client code might break.
class User {
  setPassword(password) {
    if (password.length < 8) {
      throw new Error("Password must be at least 8 characters long!");
    }
    console.log("Password set successfully");
  }
}

class AdminUser extends User {
  setPassword(password) {
    if (password.length < 6) {
      throw new Error("Password must be at least 6 characters long!");
    }
    console.log("Password set successfully");
  }
}

const user = new AdminUser();
user.setPassword("Admin1"); // Works (length = 6)
