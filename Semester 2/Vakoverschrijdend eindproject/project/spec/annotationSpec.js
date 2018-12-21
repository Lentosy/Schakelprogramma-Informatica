/**
* 	Test suite for annotating a video
*/

var request = require('request');
var annotation = require('../backend/models/annotation');
var video = require('../backend/models/video');
var data = require('./testdata.json');



const baseurl = 'http://localhost:3000/api/annotation';
const loginUrl = 'http://localhost:3000/api/user/login';
const student = {
	username:"bertdesaffel",
	password:"test"
}
var token;



/* Dummy data to simulate requests */
var dummyPostData = [
	{
		annotation: {
			videoId: data.videos[0]._id,
			user: {},
			description: "valid annotation",
			beginTime: 47,
			endTime: 47
		},
	},
	{
		annotation: {
			videoId: data.videos[0]._id,
			user: {},
			description: "negative begintimestamp",
			beginTime: -1,
			endTime: 10
		}
	},
	{
		annotation: {
			videoId: data.videos[0]._id,
			user: {},
			description: "end is smaller than begin",
			beginTime: 15,
			endTime: 10
		}
	},
]

/**
 * Geeft de informatie die meegegeven moet worden met een POST request
 * @param {Number} i De index van het object in de variabele dummyPostData
 */
function getPostArgsFor(i){
	const uploadForm = {
		videoId: dummyPostData[i].annotation.videoId,
		description: dummyPostData[i].annotation.description,
		beginTime: dummyPostData[i].annotation.beginTime,
		endTime: dummyPostData[i].annotation.endTime
	};

	const headers = {
		"Authorization": token
	};

	const postArgs = {
		url : baseurl,
		form: uploadForm,
		headers: headers
	}
	return postArgs;
}

/* Different type of annotations give different respones */
var testResponseSuite = [
	{
		description: "should return 201 if the annotation is valid",
		dummyindex: 0,
		code: 201,
	},
	{
		description: "should return 400 if the begintimestamp is negative",
		dummyindex: 1,
		code: 400,
	},
	{
		description: "should return 400 if the endtimestamp is smaller than the begintimestamp",
		dummyindex: 2,
		code: 400,
	}
];

var testPostSuite = [
	{
		description: "should add the annotation to the video if it is valid",
		dummyindex: 0,
		expected_annotation_count : 3
	}
]

describe('An Annotation that has been created', function(){

	beforeAll((done) => {
        const formData = {
            username: student.username,
            password: student.password,
        };
        const postArgs = {
            url : loginUrl,
            form: formData
        }
        request.post(postArgs, function(err, res, body){
            token = JSON.parse(body).token;
            done();
		});
	})
	
	testResponseSuite.forEach(function(test) {
		it(test.description, (done) => {
			request.post(getPostArgsFor(test.dummyindex), function(err, res, body){
				expect(res.statusCode).toEqual(test.code);
				done();
			});
		});
	});

});
