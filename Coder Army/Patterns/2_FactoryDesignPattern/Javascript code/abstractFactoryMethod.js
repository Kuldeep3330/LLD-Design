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

//Garlic bread
class GarlicBread {
    prepare() {
        throw new Error('warning prepare() needs to be implemented');
    }
}
class BasicGarlicBread extends GarlicBread {
    prepare() {
        console.log('Preparing basic garlic bread with butter and garlic!');
    }
}

class StandardGarlicBread extends GarlicBread {
    prepare() {
        console.log('Preparing cheese garlic bread with extra cheese and butter!');
    }
}

class PremiumGarlicBread extends GarlicBread {
    prepare() {
        console.log('Preparing cheese garlic bread with extra cheese and butter!');
    }
}

class BasicWheatGarlicBread extends GarlicBread {
    prepare() {
        console.log('Preparing basic wheat garlic bread with butter and garlic!');
    }
}

class StandardWheatGarlicBread extends GarlicBread {
    prepare() {
        console.log('Preparing cheese wheat garlic bread with extra cheese and butter!');
    }
}

class PremiumWheatGarlicBread extends GarlicBread {
    prepare() {
        console.log('Preparing cheese wheat garlic bread with extra cheese and butter!');
    }
}

class BurgerFactory{
    createBurger(type){
        throw new Error('createBurger() needs to be implemented ')
    }
    createGarlicBread(type){
        throw new Error('createGarlicBread() needs to be implemented ')
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

    createGarlicBread(type) {
        if (type === 'basic') {
            return new BasicGarlicBread();
        } else if (type === 'standard') {
            return new StandardGarlicBread();
        } else if (type === 'premium') {
            return new PremiumGarlicBread();
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
    createGarlicBread(type) {
        if (type === 'basic') {
            return new BasicWheatGarlicBread();
        } else if (type === 'standard') {
            return new StandardWheatGarlicBread();
        } else if (type === 'premium') {
            return new PremiumWheatGarlicBread();
        } else {
            throw new Error('Not delivering this type!');
        }
    }
}

// Client code
const type = 'basic';

const myFactory = new SinghBurger();

try {
    const burger = myFactory.createBurger(type);
    const garlic = myFactory.createGarlicBread('cheese');

    burger.prepare();
    garlic.prepare();
} catch (err) {
    console.error(err.message);
}


