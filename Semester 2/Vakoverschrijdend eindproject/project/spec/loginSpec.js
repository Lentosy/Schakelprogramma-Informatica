/**
 * Testen van de authenticatie
 */

var request = require("request");

const baseurl = 'http://localhost:3000/api/user/';

const dummyLoginData = [
    {
        username:"student",
        password:"test"
    },{
        username:"bertdesaffel",
        password:"foutpasswoord"
    },{
        username:"useronbestaand",
        password:"test"
    }
        
]

const testResponseSuite = [
    {
        description: "should return 200 if the login proceeded succesfully",
        dummyindex: 0,
        code: 200
    },
    {
        description: "should return 401 if the password is incorrect",
        dummyindex: 1,
        code: 401
    },
    {
        description: "should return 401 if the username doesn't exist",
        dummyindex: 2,
        code: 401
    }
]


function getPostArgsFor(i){
    var formData = {
        username: dummyLoginData[i].username,
        password: dummyLoginData[i].password,
    };

    const postArgs = {
        url : baseurl + "login",
        form: formData
    }

    return postArgs;
}

describe("Login", function(){
	testResponseSuite.forEach(function(test) {
		it(test.description, (done) => {
			request.post(getPostArgsFor(test.dummyindex), function(err, res, body){
				expect(res.statusCode).toEqual(test.code);
				done();
			});
		});
    });
    
    it("should return a token if the user authenticated succesfully", (done) => {
        request.post(getPostArgsFor(0), function(err, res, body){
            //expect(res.body.token).toBeDefined();
            expect(JSON.parse(body).token).toBeDefined();
            done();
        })
    });
});
