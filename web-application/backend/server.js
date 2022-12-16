const express = require('express');
const cors = require("cors");
const shell = require('shelljs');
const bodyparser = require('body-parser');
const app = express();
const port = 3000;
var messages = {
    servermessage: "None",
    clientmessage: "None",
};
function sleep(time, callback) {
    var stop = new Date().getTime();
    while (new Date().getTime() < stop + time) {
        ;
    }
    callback();
}

app.use(bodyparser.json());
app.use(cors());
app.post('/LaunchServer', function (req, res) {
    // Prepare output in JSON format  

    shell.cd('/home/rani/Desktop/programmation/c/ProgUnix/console-application/');
    shell.exec('./ServerSocket', function (error, stdout, stderr) {
        res.json("Launch Done")
    });


})
app.post('/messages', function (req, res) {
    // Prepare output in JSON format  

    recu = req.body.Clientdata;
    shell.cd('/home/rani/Desktop/programmation/c/ProgUnix/console-application/');
    shell.exec('./Server > output1.txt', function (error, stdout, stderr) {
    });
    shell.exec(recu, function (error, stdout, stderr) {
        //example of recu = './Client 5'
        messages.clientmessage = stdout;

    });
    shell.exec('cat output1.txt', function (error, stdout, stderr) {
        messages.servermessage = stdout;
        console.log(recu)
        sleep(4000, function () {
            res.json(messages)
        });

    });

})
app.post('/Sockets', function (req, res) {
    // Prepare output in JSON format  

    recu = req.body.Clientdata;
    shell.cd('/home/rani/Desktop/programmation/c/ProgUnix/console-application/');
    shell.exec(recu, function (error, stdout, stderr) {

        messages.clientmessage = stdout;

    });
    shell.exec('cat output.txt', function (error, stdout, stderr) {
        messages.servermessage = stdout;
        // console.log(recu)
        // console.log(messages)
        sleep(4000, function () {
            res.json(messages)
        });
    });

})
app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})