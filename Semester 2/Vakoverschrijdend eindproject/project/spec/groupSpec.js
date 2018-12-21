/**
* 	Test suite for annotating a video
*/

var request = require("request");
var group = require("../backend/models/group");
var data = require("./testdata.json");


const loginUrl = 'http://localhost:3000/api/user/login';
const baseurl = "http://localhost:3000/api/group";

const validFile =   "1707308;Andreas;Backx;Andreas.Backx@UGent.be;Gebruiker\n" +
                    "1306778;Anthony;Baert;Anthony.Baert@UGent.be;Gebruiker;IoT-Platform\n" + 
                    "1704941;Kenny;Blanckaert;Kenny.Blanckaert@UGent.be;Gebruiker\n"+
                    "1709102;Remi;Boret;Remi.Boret@UGent.be;Gebruiker\n"+
                    "1709203;Milan;De Buck;Milan.DeBuck@UGent.be;Gebruiker\n"+
                    "1307850;Rudolf;De Geijter;Rudolf.DeGeijter@UGent.be;Gebruiker\n"+
                    "1306427;Simon;De Gheselle;Simon.DeGheselle@UGent.be;Gebruiker\n"+
                    "1709709;Matthias;De Groote;Matthias.DeGroote@UGent.be;Gebruiker\n"+
                    "1708582;Brent;De Hauwere;Brent.DeHauwere@UGent.be;Gebruiker;IoT-Platform\n"+ 
                    "1711014;Jonas;De Maeseneer;Jonas.DeMaeseneer@UGent.be;Gebruiker\n"+
                    "8,02E+11;Eli;De Poorter;Eli.DePoorter@UGent.be;Gebruiker\n"+
                    "1614222;Bert;De Saffel;Bert.DeSaffel@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1708240;Demian;Dekoninck;Demian.Dekoninck@UGent.be;Gebruiker;IoT-Platform\n"+
                    "1701954;Nicolas;Delanghe;Nicolas.Delanghe@UGent.be;Gebruiker;IoT-Platform\n"+
                    "1707806;Thomas;Detemmerman;Thomas.Detemmerman@UGent.be;Gebruiker;IoT-Platform\n"+
                    "1509653;Victor;Devos;Victor.Devos@UGent.be;Gebruiker\n"+
                    "1711674;Simon;Gemmel;Simon.Gemmel@UGent.be;Gebruiker\n"+
                    "1706996;Glenn;Goossens;Glenn.Goossens@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1710310;Matthias;Hoebeke;Matthias.Hoebeke@UGent.be;Gebruiker\n"+
                    "1710658;Ruben;Janssens;Ruben.Janssens@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1711669;Pieter;Laebens;Pieter.Laebens@UGent.be;Gebruiker\n"+
                    "1712019;thomas;lefevere;Thomas.Lefevere@UGent.be;Gebruiker\n"+
                    "1710212;Nicolas;Legrand;Nicolas.Legrand@UGent.be;Gebruiker\n"+
                    "1711838;Arnout;Lenaerts;Arnout.Lenaerts@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "8,02003E+11;Nicola;Macoir;Nicola.Macoir@UGent.be;Gebruiker;IoT-Platform\n"+
                    "8,02002E+11;Pieter-Jan;Maenhaut;PieterJan.Maenhaut@UGent.be;Gebruiker\n"+
                    "1306860;Ward;Maes;Ward.Maes@UGent.be;Gebruiker\n"+
                    "8,01001E+11;Helga;Naessens;Helga.Naessens@UGent.be;Titularis\n"+
                    "8,01001E+11;Veerle;Ongenae;Veerle.Ongenae@UGent.be;Medelesgever\n"+
                    "870085;Martijn;Saelens;Martijn.Saelens@UGent.be;Gebruiker\n"+
                    "1711285;Muhammed;Sari;Muhammed.Sari@UGent.be;Gebruiker\n"+
                    "1710647;Manu;Schoenmakers;Manu.Schoenmakers@UGent.be;Gebruiker\n"+
                    "1708568;Laura;Snyers;Laura.Snyers@UGent.be;Gebruiker\n"+
                    "1708643;Bryan;Stael;Bryan.Stael@UGent.be;Gebruiker\n"+
                    "1004148;Timothy;Thiecke;Timothy.Thiecke@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1705806;Timon;Van der Straeten;Timon.VanderStraeten@UGent.be;Gebruiker\n"+
                    "1702421;Nick;van Hurck;Nick.vanHurck@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1307303;Bram;Van Kerschaver;Bram.VanKerschaver@UGent.be;Gebruiker\n"+
                    "8,02002E+11;Ann;Van Overberge;Ann.VanOverberge@UGent.be;Medelesgever;Annotatietool voor video\n"+
                    "1708928;Emiel;Vandenbussche;Emiel.Vandenbussche@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1302074;Cedric;Vanhaverbeke;Cedric.Vanhaverbeke@UGent.be;Gebruiker;IoT-Platform\n"

const invalidFile = "1707308;AndreasBackx;Andreas.Backx@UGent.be;Gebruiker\n" +
                    "1306778;Anthony;Baert;Anthony.Baert@UGent.be;Gebruiker;IoT-Platform\n" + 
                    "1704941;Kenny;Blanckaert;Kenny.Blanckaert@UGent.be;Gebruiker\n"+
                    "1709102;Remi;Boret;Remi.Boret@UGent.be;Gebruiker\n"+
                    "1709203;Milan;De Buck;Milan.DeBuck@UGent.be;Gebruiker\n"+
                    "1307850;Rudolf;De Geijter;Rudolf.DeGeijter@UGent.be;Gebruiker\n"+
                    "1306427;Simon;De Gheselle;Simon.DeGheselle@UGent.be;Gebruiker\n"+
                    "1709709;Matthias;De Groote;Matthias.DeGroote@UGent.be;Gebruiker\n"+
                    "1708582;Brent;De Hauwere;Brent.DeHauwere@UGent.be;Gebruiker;IoT-Platform\n"+ 
                    "1711014;Jonas;De Maeseneer;Jonas.DeMaeseneer@UGent.be;Gebruiker\n"+
                    "8,02E+11;Eli;De Poorter;Eli.DePoorter@UGent.be;Gebruiker\n"+
                    "1614222;Bert;De Saffel;Bert.DeSaffel@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1708240;Demian;Dekoninck;Demian.Dekoninck@UGent.be;Gebruiker;IoT-Platform\n"+
                    "1701954;Nicolas;Delanghe;Nicolas.Delanghe@UGent.be;Gebruiker;IoT-Platform\n"+
                    "1707806;Thomas;Detemmerman;Thomas.Detemmerman@UGent.be;Gebruiker;IoT-Platform\n"+
                    "1509653;Victor;Devos;Victor.Devos@UGent.be;Gebruiker\n"+
                    "1711674;Simon;Gemmel;Simon.Gemmel@UGent.be;Gebruiker\n"+
                    "1706996;Glenn;Goossens;Glenn.Goossens@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1710310;Matthias;Hoebeke;Matthias.Hoebeke@UGent.be;Gebruiker\n"+
                    "1710658;Ruben;Janssens;Ruben.Janssens@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1711669;Pieter;Laebens;Pieter.Laebens@UGent.be;Gebruiker\n"+
                    "1712019;thomas;lefevere;Thomas.Lefevere@UGent.be;Gebruiker\n"+
                    "1710212;Nicolas;Legrand;Nicolas.Legrand@UGent.be;Gebruiker\n"+
                    "1711838;Arnout;Lenaerts;Arnout.Lenaerts@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "8,02003E+11;Nicola;Macoir;Nicola.Macoir@UGent.be;Gebruiker;IoT-Platform\n"+
                    "8,02002E+11;Pieter-Jan;Maenhaut;PieterJan.Maenhaut@UGent.be;Gebruiker\n"+
                    "1306860;Ward;Maes;Ward.Maes@UGent.be;Gebruiker\n"+
                    "8,01001E+11;Helga;Naessens;Helga.Naessens@UGent.be;Titularis\n"+
                    "8,01001E+11;Veerle;Ongenae;Veerle.Ongenae@UGent.be;Medelesgever\n"+
                    "870085;Martijn;Saelens;Martijn.Saelens@UGent.be;Gebruiker\n"+
                    "1711285;Muhammed;Sari;Muhammed.Sari@UGent.be;Gebruiker\n"+
                    "1710647;Manu;Schoenmakers;Manu.Schoenmakers@UGent.be;Gebruiker\n"+
                    "1708568;Laura;Snyers;Laura.Snyers@UGent.be;Gebruiker\n"+
                    "1708643;Bryan;Stael;Bryan.Stael@UGent.be;Gebruiker\n"+
                    "1004148;Timothy;Thiecke;Timothy.Thiecke@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1705806;Timon;Van der Straeten;Timon.VanderStraeten@UGent.be;Gebruiker\n"+
                    "1702421;Nick;van Hurck;Nick.vanHurck@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1307303;Bram;Van Kerschaver;Bram.VanKerschaver@UGent.be;Gebruiker\n"+
                    "8,02002E+11;Ann;Van Overberge;Ann.VanOverberge@UGent.be;Medelesgever;Annotatietool voor video\n"+
                    "1708928;Emiel;Vandenbussche;Emiel.Vandenbussche@UGent.be;Gebruiker;Annotatietool voor video\n"+
                    "1302074;Cedric;Vanhaverbeke;Cedric.Vanhaverbeke@UGent.be;Gebruiker;IoT-Platform\n"

const docent = {
	username:"glenngoossens",
	password:"test"
}
var token;

describe("Uploading a csv file", function(){

    beforeAll((done) => {
        const formData = {
            username: docent.username,
            password: docent.password,
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

    it("should return 201 if the file is valid", (done) => {
        var req = request.post({url: baseurl, headers: {"Authorization": token}} ,function(err, response, body){
            expect(response.statusCode).toBe(201);
            done();
        });
        var form = req.form();
        form.append("studentsFile", validFile, {
            filename: "./resources/export.csv",
            contentType: "text/plain"
        });
        form.append("name", "npm test valid file")
    });

    if("should return 401 if the file is invalid", (done) => {
        var req = request.post({url: baseurl, headers: {"Authorization": token}} ,function(err, response, body){
            expect(response.statusCode).toBe(201);
            done();
        });
        var form = req.form();
        form.append("studentsFile", invalidFile, {
            filename: "./resources/export.csv",
            contentType: "text/plain"
        });
        form.append("name", "invalid")
    });
})

