/*
💬 Important points
1.JS does not enforce exception hierarchy rules — you can throw any error from an overriding method.
2.We manually check error type using instanceof if needed.
3.The concept of "narrower exceptions" is only a best practice in JS, not a language rule.
 */

/*
├── Error                 <-- Base class for all errors
│   ├── EvalError         <-- Error related to eval() function
│   ├── RangeError        <-- Value not in allowed range
│   ├── ReferenceError    <-- Invalid reference (e.g., using an undefined variable)
│   ├── SyntaxError       <-- Syntax parsing error (e.g., during eval or parsing)
│   ├── TypeError         <-- Wrong type (e.g., calling non-function)
│   ├── URIError          <-- Malformed URI functions
*/

class Parent {
  getValue() {
    throw new Error("Parent error");
  }
}

class Child extends Parent {
  getValue() {
    throw new RangeError("Child error");
    // throw new SyntaxError("Child error"); // Conceptually "broader", but no restriction in JS
  }
}

class Client {
  constructor(p) {
    this.p = p;
  }

  takeValue() {
    try {
      this.p.getValue();
    } catch (e) {
      if (e instanceof RangeError) {
        console.log("Range error occurred:", e.message);
      } else if (e instanceof Error) {
        console.log("Error occurred:", e.message);
      }
    }
  }
}

// Create instances
const parent = new Parent();
const child = new Child();

// const client = new Client(parent);
const client = new Client(child);

client.takeValue();
