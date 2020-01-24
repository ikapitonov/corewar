function Field(size){
    this.size = size;
    let fieldArray = new Array();
    for(let i=0; i<size; i++){
        fieldArray[i] = new Array();
        for(let j=0; j<size; j++){
            fieldArray[i][j] = document.createElement("div");
            fieldArray[i][j].style.height = 20 + "px";
            fieldArray[i][j].style.width = 20 + "px";
            fieldArray[i][j].style.background = "black";
            fieldArray[i][j].style.margin = 0;
            fieldArray[i][j].style.padding = 0;
            fieldArray[i][j].style.border = 1 + "px";
            fieldArray[i][j].style.borderStyle = "solid";
            fieldArray[i][j].style.borderColor = "black";
            fieldArray[i][j].style.borderRadius = 5 + "px";
            fieldArray[i][j].style.boxSizing = "border-box";
        }
    }
    this.arr = fieldArray;
    this.div = document.createElement("div");
    document.body.appendChild(this.div);
    this.div.className = "field";
    this.div.style.marginLeft = "auto";
    this.div.style.marginRight = "auto";
    this.div.style.background = "black";
    this.div.style.height = size*20 + "px";
    this.div.style.width = size*20 + "px";
    this.rowArray = new Array();
    for(let i=0; i<size; i++){
        this.rowArray[i] = document.createElement("div");
        this.rowArray[i].style.display = "flex";
        this.div.appendChild(this.rowArray[i]);    
    }
    for(let i=0; i<size; i++)
        for(let j=0; j<size; j++){
            this.rowArray[j].appendChild(this.arr[i][j]);
    }
}

function Snake(){
    this.length = 4;
    this.maxlength = this.length - 1;
    valuelength.innerHTML = this.length - 1;
    valueMaxlength.innerHTML = this.maxlength;
    let snakeArray = new Array();
    for(let i=0; i<this.length; i++){
        snakeArray[i] = {
            x: 9-i,
            y: 9
        }
    }
    this.arr = snakeArray;
    this.head = {
        x: 9,
        y: 9
    }
    this.stepX = 1;
    this.stepY = 0;
    this.go = function(x, y){
        if(x<0)
            x=field.size+x;
        if(y<0)
            y=field.size+y;
        let f = 0;
        for(let k=0; k<this.arr.length; k++){
            if(this.arr[k].x == this.head.x && this.arr[k].y == this.head.y)
                f = true;
        }
        if(f){
            let i=0;
            while(this.arr[this.arr.length - 1].x != this.head.x || this.arr[this.arr.length - 1].y != this.head.y ){
                this.length--;
                this.clear(this.arr[this.arr.length - (i+1)].x, this.arr[this.arr.length - (i+1)].y)
                this.arr.pop();
            }
            valuelength.innerHTML = this.length - 1;
        }
        field.arr[x][y].style.background = "green";
        this.arr.unshift([]);
        Object.assign(this.arr[0], this.head);
        if(x == food.x && y == food.y){
            this.length++;
            valuelength.innerHTML = this.length - 1;
            if(this.length - 1 > this.maxlength){
                this.maxlength++;
                valueMaxlength.innerHTML = this.maxlength;
            }
            let f1 = true;
            while(f1)
                {
                    food = new Food();
                    f1 = false;
                    for(let k=0; k<this.arr.length; k++){
                        if((this.arr[k].x == food.x || this.arr[k].x + field.size == food.x) &&
                        	(this.arr[k].y == food.y || this.arr[k].y  + field.size == food.y))
                            f1 = true;
                    }
                }
            field.arr[food.x][food.y].style.background = "red";
        } 
        else
            this.arr.pop();     
    }
    this.clear = function(x, y){
        if(x<0)
            x=field.size+x;
        if(y<0)
            y=field.size+y;
        field.arr[x][y].style.background = "black";
    }
}

function Food(){
    this.x = Math.round(Math.random()*(field.size-1));
    this.y = Math.round(Math.random()*(field.size-1));
}

function Controls(size){
	this.div = document.createElement("div");
	this.div.style.textAlign = "center";
	this.div.style.height = size + "px";
	this.div.style.width = size + "px";
	this.div.style.marginLeft = "auto";
    this.div.style.marginRight = "auto";
    this.div.style.marginTop = 50 + "px";
    this.Up = document.createElement("button");
    this.Up.style.margin = "auto";
    this.Up.innerHTML = "↑";
    this.Down = document.createElement("button");
    this.Down.style.margin = "auto";
    this.Down.innerHTML = "↓";
    this.Left = document.createElement("button");
    this.Left.style.marginLeft = "0";
    this.Left.style.marginRight = "auto";
    this.Left.innerHTML = "←";
    this.Right = document.createElement("button");
    this.Right.style.marginLeft = "auto";
    this.Right.style.marginRight = "0";
    this.Right.innerHTML = "→";
    this.LR = document.createElement("div");
    this.LR.style.display = "flex";
    this.LR.appendChild(this.Left);
    this.LR.appendChild(this.Right);
    this.div.appendChild(this.Up);
    this.div.appendChild(this.LR);
    this.div.appendChild(this.Down);
    this.buttons = this.div.getElementsByTagName("button");
    for (let i = 0; i < 4; i++){
    	this.buttons[i].style.height = size / 3 + "px";
    	this.buttons[i].style.width = size / 3 + "px";
    	this.buttons[i].style.borderRadius = 10 + "px";
    	this.buttons[i].style.fontSize = 50 + "px";
    	this.buttons[i].style.fontWeight = 900;
    }
	document.body.appendChild(this.div);
}

var valuelength = document.getElementById("valuelength");
var valueMaxlength = document.getElementById("valueMaxlength");
var snake = new Snake();
var field = new Field(25);
var food = new Food();
var controls = new Controls(300);
field.arr[food.x][food.y].style.background = "red";

setTimeout(function run(){
    snake.head.x += snake.stepX;
    snake.head.y += snake.stepY;
    snake.go(snake.head.x, snake.head.y);
    snake.clear(snake.arr[snake.arr.length - 1].x, snake.arr[snake.arr.length - 1].y);
    if(snake.head.x==field.size-1)
        snake.head.x = -1;
    if(snake.head.y==field.size-1)
        snake.head.y = -1;
    if(snake.head.x<0 && snake.stepX<0)
        snake.head.x = field.size-1;
    if(snake.head.y<0 && snake.stepY<0)
        snake.head.y = field.size-1;
    setTimeout(run, 100);
}, 100);

function turnLeft(){
	if(snake.arr[1].y == snake.head.y)
                return ;
            if(snake.head.x<0)
                snake.head.x = field.size-1;
            snake.stepX = -1;
            snake.stepY = 0;
}
function turnUp(){
	 if(snake.arr[1].x == snake.head.x)
                return ;
            if(snake.head.y<0)
                snake.head.y = field.size-1;
            snake.stepX = 0;
            snake.stepY = -1;
}
function turnRight(){
	if(snake.arr[1].y== snake.head.y)
                return ;
            if(snake.head.x==field.size-1)
                snake.head.x = -1;
            snake.stepX = 1;
            snake.stepY = 0;
}
function turnDown(){
	if(snake.arr[1].x == snake.head.x)
                return ;
             if(snake.head.y==field.size-1)
                 snake.head.y = -1;
            snake.stepX = 0;
            snake.stepY = 1;
}

controls.Left.ontouchstart = function(e){
	turnLeft();
}
controls.Right.ontouchstart = function(e){
	turnRight();
}
controls.Up.ontouchstart = function(e){
	turnUp();
}
controls.Down.ontouchstart = function(e){
	turnDown();
}


window.onkeydown = function(e){
    switch(e.keyCode){
        case 37:
            turnLeft();
            break;
        case 38:
            turnDown();
            break;
        case 39:
            turnRight();
            break;
        case 40:
            turnUp();
            break;
    }
}
