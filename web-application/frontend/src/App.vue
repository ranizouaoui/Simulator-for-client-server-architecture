<template>
  <div>
    <nav class="navbar navbar-light bg-light">
      <div class="container-fluid">
        <a class="navbar-brand" style="margin: inherit" href="#">
          <img
            src="../src/assets/isi-logo.jpg"
            alt=""
            width="70"
            height="30"
            class="d-inline-block align-text-top"
          />
          Higher institute of computer science
        </a>
      </div>
    </nav>
    <div class="container">
      <br />
      <div class="form-check form-switch">
        <input
          class="form-check-input"
          type="checkbox"
          @click="ResetValues()"
          role="switch"
          v-model="checked"
          id="flexSwitchCheckChecked"
          checked
        />
        <label
          v-if="checked"
          class="form-check-label"
          for="flexSwitchCheckChecked"
          ><h5>Communication with named pipe</h5></label
        >
        <label v-else class="form-check-label" for="flexSwitchCheckChecked"
          ><h5>Communication with sockets</h5></label
        >
      </div>
      <br />
      <div class="accordion" id="accordionExample">
        <div class="accordion-item">
          <h2 class="accordion-header" id="headingOne">
            <button
              class="accordion-button"
              type="button"
              data-bs-toggle="collapse"
              data-bs-target="#collapseOne"
              aria-expanded="true"
              aria-controls="collapseOne"
            >
              Configuration
            </button>
          </h2>
          <div
            id="collapseOne"
            class="accordion-collapse collapse show"
            aria-labelledby="headingOne"
            data-bs-parent="#accordionExample"
          >
            <div class="accordion-body">
              <div class="accordion accordion-flush" id="accordionFlushExample">
                <div class="accordion-item">
                  <h2 class="accordion-header" id="flush-headingOne">
                    <button
                      class="accordion-button collapsed"
                      type="button"
                      data-bs-toggle="collapse"
                      data-bs-target="#flush-collapseOne"
                      aria-expanded="false"
                      aria-controls="flush-collapseOne"
                    >
                      Server Setup
                    </button>
                  </h2>
                  <div
                    id="flush-collapseOne"
                    class="accordion-collapse collapse"
                    aria-labelledby="flush-headingOne"
                    data-bs-parent="#accordionFlushExample"
                  >
                    <div class="accordion-body">
                      <div class="mb-3">
                        <label for="exampleFormControlInput1" class="form-label"
                          >Server name</label
                        >
                        <input
                          type="text"
                          class="form-control"
                          id="exampleFormControlInput1"
                          placeholder="Example: localhost"
                          v-model="servername"
                        />
                      </div>
                    </div>
                  </div>
                </div>

                <div class="accordion-item">
                  <h2 class="accordion-header" id="flush-headingThree">
                    <button
                      class="accordion-button collapsed"
                      type="button"
                      data-bs-toggle="collapse"
                      data-bs-target="#flush-collapseThree"
                      aria-expanded="false"
                      aria-controls="flush-collapseThree"
                    >
                      Clients Setup
                    </button>
                  </h2>
                  <div
                    id="flush-collapseThree"
                    class="accordion-collapse collapse"
                    aria-labelledby="flush-headingThree"
                    data-bs-parent="#accordionFlushExample"
                  >
                    <div class="accordion-body">
                      <div class="form-outline" style="width: 22rem">
                        <label class="form-label" for="typeNumber"
                          >Number of clients</label
                        >
                        <input
                          min="1"
                          max="4"
                          v-model="ClientsNumber"
                          type="number"
                          id="typeNumber"
                          class="form-control"
                        />
                      </div>
                    </div>
                  </div>
                </div>
                <div class="accordion-item">
                  <h2 class="accordion-header" id="flush-headingTwo">
                    <button
                      class="accordion-button collapsed"
                      type="button"
                      data-bs-toggle="collapse"
                      data-bs-target="#flush-collapseTwo"
                      aria-expanded="false"
                      aria-controls="flush-collapseTwo"
                    >
                      Optional configuration
                    </button>
                  </h2>
                  <div
                    id="flush-collapseTwo"
                    class="accordion-collapse collapse"
                    aria-labelledby="flush-headingTwo"
                    data-bs-parent="#accordionFlushExample"
                  ></div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="container" v-if="checked">
      <br />
      <h2>Simulation <span class="badge bg-secondary">Pipes</span></h2>
      <br />
      <div class="row align-items-center">
        <div class="col">
          <div
            class="card border-secondary mb-3"
            v-for="item in ClientsNumber"
            :key="item"
            style="max-width: 16rem"
          >
            <div class="card bg-light" style="max-width: 16rem">
              <div class="card-header text-center">Client {{ item }}</div>
              <div class="card-body">
                <form class="row g-3">
                  <div>
                    <label for="inputPassword2" class="visually-hidden"
                      >Number</label
                    >
                    <input
                      type="number"
                      class="form-control"
                      id="inputPassword2"
                      placeholder="Random number"
                      v-model="num[item]"
                    />
                  </div>
                  <div>
                    <button
                      type="button"
                      class="btn btn-success"
                      @click="SendNumberPipe(item, num[item])"
                    >
                      Send
                    </button>
                  </div>
                </form>
                <p class="card-text" v-if="client[item]">
                  {{ client[item].clientmessage }}
                </p>
              </div>
            </div>
          </div>
        </div>
        <div class="col">
          <div>
            <p class="h6 text-center">Fifo1 (Requests)</p>
            <div id="box">
              <div class="square1" v-if="send"></div>
            </div>
            <p class="h6 text-center">Fifo2 (Response)</p>
            <div id="box">
              <div class="square2" v-if="send"></div>
            </div>
          </div>
        </div>
        <div class="col" style="margin-left: 80px">
          <div class="card border-secondary mb-3" style="max-width: 16rem">
            <div class="card bg-light" style="max-width: 16rem">
              <div class="card-header text-center">{{ servername }}</div>
              <div class="card-body">
                <p class="card-text">
                  {{ servermessage }}
                </p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="container" v-if="checked == false">
      <br />
      <h2>Simulation <span class="badge bg-secondary">Sockets</span></h2>
      <br />
      <div class="row align-items-center">
        <div class="col">
          <div
            class="card border-secondary mb-3"
            v-for="item in ClientsNumber"
            :key="item"
            style="max-width: 16rem"
          >
            <div class="card bg-light mb-3" style="max-width: 16rem">
              <div class="card-header text-center">Client</div>
              <div class="card-body">
                <form class="row g-3">
                  <div>
                    <label for="inputPassword2" class="visually-hidden"
                      >Number</label
                    >
                    <input
                      type="number"
                      class="form-control"
                      id="inputPassword2"
                      placeholder="Random number"
                      v-model="num[item]"
                    />
                  </div>
                  <div>
                    <button
                      type="button"
                      class="btn btn-success"
                      @click="SendNumberSocket(item, num[item])"
                    >
                      Send
                    </button>
                  </div>
                </form>
                <p class="card-text" v-if="client[item]">
                  {{ client[item].clientmessage }}
                </p>
              </div>
            </div>
          </div>
        </div>
        <div class="col">
          <div>
            <img
              src="../src/assets/mail.png"
              alt=""
              width="50"
              height="50"
              v-if="send"
              class="square3"
            />
          </div>
        </div>

        <div class="col">
          <div class="card border-secondary mb-3" style="max-width: 14rem">
            <div class="card bg-light mb-3" style="max-width: 14rem">
              <div class="card-header text-center">{{ servername }}</div>
              <div class="card-body">
                <p class="card-text">
                  {{ servermessage }}
                </p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";
//import { concat } from 'shelljs/commands';
export default {
  name: "App",
  data() {
    return {
      servermessage: "",
      client: [
        {
          clientmessage: "No data",
          servermessage: "",
        },
      ],
      send: false,

      servername: "Server",
      ClientsNumber: 2,
      checked: true,
      picked: "One",
      num: [1],
    };
  },
  components: {},
  methods: {
    SendNumberPipe(item, number) {
      let text1 = "./Client";
      let text3 = text1.concat(" ", number);
      this.send = true;
      axios
        .post("http://localhost:3000/messages", {
          Clientdata: text3,
        })
        .then((response) => {
          // console.log(response);
          //   console.log(response.data.clientmessage);
          //  this.client[1]["clientmessage"] = response.data.clientmessage;
          this.send = false;

          this.client[item] = {
            clientmessage: response.data.clientmessage,
            servermessage: response.data.servermessage,
          };
          this.servermessage = this.servermessage
            .concat(" ")
            .concat(response.data.servermessage);
          // console.log(this.client[1].clientmessage);
          // this.servermessage = response.data.servermessage;
          //  this.messages.clientmessage = response.data.clientmessage;
        })
        .catch(function (error) {
          console.log(error);
        });
    },
    SendNumberSocket(item, number) {
      let text1 = "./ClientSocket";
      let text3 = text1.concat(" ", number);
      this.send = true;
      axios
        .post("http://localhost:3000/Sockets", {
          Clientdata: text3,
        })
        .then((response) => {
          // console.log(response);
          //   console.log(response.data.clientmessage);
          //  this.client[1]["clientmessage"] = response.data.clientmessage;
          this.send = false;
          this.client[item] = {
            clientmessage: response.data.clientmessage,
            servermessage: response.data.servermessage,
          };
          this.servermessage = this.servermessage
            .concat(" ")
            .concat(response.data.servermessage);
        })
        .catch(function (error) {
          console.log(error);
        });
    },
    ResetValues() {
      this.servermessage = "";
      this.num = [1];
      this.client = [
        {
          clientmessage: "No data",
          servermessage: "",
        },
      ];
    },
  },
  created() {
    axios
      .post("http://localhost:3000/LaunchServer", {
        Clientdata: "Launch the server",
      })
      .then((response) => {
        console.log(response);
      })
      .catch(function (error) {
        console.log(error);
      });
  },
};
</script>
<style>
@keyframes moveRight {
  from {
    transform: translateX(0);
  }

  to {
    transform: translateX(550%);
  }
}

@keyframes changeColor {
  from,
  95% {
    background-color: red;
  }

  100% {
    background-color: white;
  }
}

.square1 {
  animation: moveRight 2s linear infinite, changeColor 2s linear infinite;
  height: 45px;
  width: 45px;
  animation-iteration-count: 1;
}
#box {
  border: 2px solid;
  padding: 0.2px;
  margin-bottom: 10px;
  height: 50px;
}
.square2 {
  animation: moveleft 2s linear infinite, changeColor2 2s linear infinite;
  height: 45px;
  width: 45px;
  animation-iteration-count: 1;
  animation-delay: 2.5s;
}
.square3 {
  animation: move 3s linear infinite;
  height: 45px;
  width: 50px;
  animation-iteration-count: 1;
}
@keyframes move {
  0% {
    transform: translate(0);
  }

  50% {
    transform: translate(300px);
  }
}
@keyframes moveleft {
  from {
    transform: translateX(550%);
  }

  to {
    transform: translateX(-50%);
  }
}

@keyframes changeColor2 {
  from,
  90% {
    background-color: green;
  }

  100% {
    background-color: white;
  }
}
</style>
