// WALK INTERFACES
class WalkRobot {
  walk() {
    throw new Error("Method 'walk()' must be implemented.");
  }
}

class NormalWalk extends WalkRobot {
  walk() {
    console.log("walking Robot");
  }
}

class NoWalk extends WalkRobot {
  walk() {
    console.log("non-walking Robot");
  }
}

// TALK INTERFACES
class TalkRobot {
  talk() {
    throw new Error("Method 'talk()' must be implemented.");
  }
}

class NormalTalk extends TalkRobot {
  talk() {
    console.log("Talking Robot");
  }
}

class NoTalk extends TalkRobot {
  talk() {
    console.log("non-talking Robot");
  }
}

// FLY INTERFACES
class FlyRobot {
  fly() {
    throw new Error("Method 'fly()' must be implemented.");
  }
}

class NormalFly extends FlyRobot {
  fly() {
    console.log("flying Robot");
  }
}

class NoFly extends FlyRobot {
  fly() {
    console.log("non-flying Robot");
  }
}

//context class
class Robot {
  constructor(walkRobot, talkRobot, flyRobot) {
    this.walkRobot = walkRobot;
    this.talkRobot = talkRobot;
    this.flyRobot = flyRobot;
  }

  walk() {
    this.walkRobot.walk();
  }

  talk() {
    this.talkRobot.talk();
  }

  fly() {
    this.flyRobot.fly();
  }

  projection() {
    throw new Error("Method 'projection()' must be implemented.");
  }
}

class CompanionRobot extends Robot {
  constructor(walk, talk, fly) {
    super(walk, talk, fly);
  }
  /*
  in C++
  public:
    CompanionRobot(WalkRobot *w, TalkRobot *t, FlyRobot *f) : Robot(w, t, f) {}
   */

  projection() {
    console.log("Displaying friendly companion features");
  }
}

class WorkerRobot extends Robot {
  constructor(walk, talk, fly) {
    super(walk, talk, fly);
  }

  projection() {
    console.log("Displaying worker efficiency features");
  }
}


const robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NormalFly());
robot1.walk();
robot1.talk();
robot1.fly();
robot1.projection();

console.log("-----");

const robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
robot2.walk();
robot2.talk();
robot2.fly();
robot2.projection();