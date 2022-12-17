# Simulator for client-server architecture

<div align="center"> 
<img src="https://github.com/ranizouaoui/Simulator-for-client-server-architecture/blob/main/thumbnail.png" alt="" />
 </div>

## Preface
Our solution ensures communication between clients and servers via two named pipes. We have synchronized the application with the signals that wake up the client and the server upon receipt of messages. Our solution also provides client-server communication via sockets in parallel mode on the server side. The manipulation of the different architectures is done through a graphical interface which is made with the “Vue.Js” framework. The communication between the interface and the outputs of the C programs is done through a server that I have implemented with the “Express.Js” tool. We used the “Shell.Js” tool, which allows us to execute “Shell” commands On a “Node.Js” environment, to launch the executables and retrieve the outputs of C programs.

<h4> Why I chose Vuejs framework? </h4>

Simply, vuejs has a big community, especially vuejs and Nodejs. Vue js is widely used all over the world. Do you know that Nentendre website, Gitlab, Laracast, Laravel Vapor and other well-known sites are developed with vuejs.

This is definitely the framework I recommend for frontend development.

## Install

Perform the following steps:

1- Download and install <a href="https://nodejs.org/en/">Node.js</a>.<br/>
2- Download and install <a href="https://nodejs.org/en/">Visual Studio Code(VS Code)</a>.<br/>
3- Install vetur extension for VS Code.<br/>
4- Clone this repository.<br/>
5- Download and install npm packages.<br/>
```
npm install
```

## How to launch the app ?

```
cd Code/web-application/backend
node server.js
cd Code/web-application/frontend
npm run serve
```

## Compiles and minifies for production
```
cd Code/web-application/frontend
npm run build
```

## Lints and fixes files
```
cd Code/web-application/frontend
npm run lint
```
## Project Map
<div align="center"> 
<img src="https://github.com/ranizouaoui/Simulator-for-client-server-architecture/blob/main/Project-Map.png" alt="" />
 </div>
 
## Want more details?

For more details or if you want to recommend me for other projects. Just contact me on my email: <strong> ranizouaouicontact@gmail.com </strong>
