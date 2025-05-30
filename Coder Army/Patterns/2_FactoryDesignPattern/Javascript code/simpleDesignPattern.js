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

class BurgerFactory {
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

// Usage
const factory = new BurgerFactory();
const burger = factory.createBurger('basic');
burger.prepare();  