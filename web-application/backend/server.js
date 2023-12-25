const express = require('express');
const cors = require("cors");
const bodyparser = require('body-parser');
const app = express();
const port = 3000;
var messages = "None";

app.use(bodyparser.json());
app.use(cors());

app.post('/messages', function (req, res) {
    // Prepare output in JSON format  

    res.json(messages);
})

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})