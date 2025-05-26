class Singleton{
    static #instance=null ///instance static

    constructor(){
        if(Singleton.#instance){
            throw new Error("Use Singleton.getInstance() instead of new.");
        }
        console.log("Singleton constructor called, new instance created!");
        }

        static getInstance(){
            if(Singleton.#instance===null){
                Singleton.#instance= new Singleton()
            }
            return Singleton.#instance
        }
}

const s1 = Singleton.getInstance();
const s2 = Singleton.getInstance();

console.log(s1 === s2);