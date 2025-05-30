class Burger {
    prepare() {
        throw new Error('warning prepare() needs to be implemented');
    }
}

class BasicBurger extends Burger {
    prepare() {
        console.log('Preparing basic burger with bun, patty and Ketchup!');
    }
}

class StandardBurger extends Burger {
    prepare() {
        console.log('Preparing Standard burger with bun, patty, cheese, lettuce and Ketchup!');
    }
}

class PremiumBurger extends Burger {
    prepare() {
        console.log('Preparing premium burger with bun, patty, extra cheese, lettuce and Ketchup!');
    }
}

class BasicWheatBurger extends Burger {
    prepare() {
        console.log('Preparing basic wheat burger with bun, patty and Ketchup!');
    }
}

class StandardWheatBurger extends Burger {
    prepare() {
        console.log('Preparing Standard wheat burger with bun, patty, cheese, lettuce and Ketchup!');
    }
}

class PremiumWheatBurger extends Burger {
    prepare() {
        console.log('Preparing premium wheat burger with bun, patty, extra cheese, lettuce and Ketchup!');
    }
}

class BurgerFactory{
    createBurger(type){
        throw new Error('createBurger() needs to be implemented ')
    }
}

class SinghBurger extends BurgerFactory{
    createBurger(type) {
        if (type === 'basic') {
            return new BasicBurger();
        } else if (type === 'standard') {
            return new StandardBurger();
        } else if (type === 'premium') {
            return new PremiumBurger();
        } else {
            throw new Error('Not delivering this type!');
        }
    }
}

class KingBurger extends BurgerFactory{
    createBurger(type) {
        if (type === 'basic') {
            return new BasicWheatBurger();
        } else if (type === 'standard') {
            return new StandardWheatBurger();
        } else if (type === 'premium') {
            return new PremiumWheatBurger();
        } else {
            throw new Error('Not delivering this type!');
        }
    }
}

// Client code
const type = 'basic'; 

const myFactory = new SinghBurger(); 
const burger = myFactory.createBurger(type);

burger.prepare();

const myFactory_2= new KingBurger()
const burger_2= myFactory_2.createBurger(type)
burger_2.prepare()

