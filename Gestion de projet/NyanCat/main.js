// ============== DEBUT ================= //
import {create_obstacle} from './js/Obstacle';
create_obstacle();
var canvas = document.querySelector('.canvas'),
	context = canvas.getContext('2d');
context.canvas.width = window.innerWidth;
context.canvas.height = window.innerHeight;


//SOURIS

var mouse = {
	x: 680,
	y: 360
};
canvas.addEventListener('mousemove', function(e) {

	mouse.x = e.clientX;
	mouse.y = e.clientY;
});

var iter = false;
var ref = {};
var refTail = {};

// =============== CREATION DE L'ETOILE =============== //

var coords = [];

function create_star() {
	var coord = {};
	coord.x = context.canvas.width;
	coord.y = Math.random() * context.canvas.height;
	coord.width = 10;
	coord.speed = {};
	coord.speed.x = 20;
	coord.speed.y = 0;
	coord.style = 'white';
	coords.push(coord);
}

function delete_star() {
	coords.forEach(function(el, index) {
		if (el.x < 0) {
			coords.splice(index, 1);
		}
	})
}

function star() {
	context.clearRect(0, 0, canvas.width, canvas.height);
	for (var i = 0; i < coords.length; i++) {
		var coord = coords[i];

		coord.x += -coord.speed.x;
		coord.y += coord.speed.y;

		context.beginPath();
		context.rect(coord.x, coord.y, 20, 5);
		context.rect(coord.x + 7, coord.y - 7, 5, 20);
		context.fillStyle = coord.style;
		context.fill();
	}

}

// ============== DESSIN DU CHAT ================ //
var tails = [];

function create_tail() {
	var tail = {};
	tail.x = refTail.x;
	tail.y = refTail.y;
	tail.width = 10;
	tails.push(tail);

}

function remove_tail() {
	tails.forEach(function(el, index) {
		if (el.x < 0) {
			tails.splice(index, 1);
		}
	})
}

var tailVersion = true;

function draw() {

	for (var i = 0; i < tails.length; i++) {
		var tail = tails[i];

		tail.x += -40;
		tail.y += 0;
		tail.width++;

		// ============== QUEUE ================= //

		context.beginPath();

		if (tailVersion) {
			context.fillStyle = '#ff0000';
			context.fillRect(tail.x, tail.y - 45, 40, 15);
			context.fillStyle = '#ff9900';
			context.fillRect(tail.x, tail.y - 30, 40, 15);
			context.fillStyle = '#ffff00';
			context.fillRect(tail.x, tail.y - 15, 40, 15);
			context.fillStyle = '#33ff00';
			context.fillRect(tail.x, tail.y, 40, 15);
			context.fillStyle = '#0099ff';
			context.fillRect(tail.x, tail.y + 15, 40, 15);
			context.fillStyle = '#6633ff';
			context.fillRect(tail.x, tail.y + 30, 40, 15);
		} else {

			context.fillStyle = '#ff0000';
			context.fillRect(tail.x, tail.y - 35, 40, 15);
			context.fillStyle = '#ff9900';
			context.fillRect(tail.x, tail.y - 25, 40, 15);
			context.fillStyle = '#ffff00';
			context.fillRect(tail.x, tail.y - 10, 40, 15);
			context.fillStyle = '#33ff00';
			context.fillRect(tail.x, tail.y + 5, 40, 15);
			context.fillStyle = '#0099ff';
			context.fillRect(tail.x, tail.y + 20, 40, 15);
			context.fillStyle = '#6633ff';
			context.fillRect(tail.x, tail.y + 35, 40, 15);
		}

	}
	tailVersion = !tailVersion;
}

window.addEventListener('click', function() {
	iter = !iter;
})

function nyan() {
	// ==============    CHAT    ================= //

	//ARRIERE

	context.beginPath();
	context.fillStyle = '#ffcc99';
	context.fillRect(ref.x - 10, ref.y - 55, 150, 120);

	//HAUT

	context.fillStyle = '#ff99ff';
	context.fillRect(ref.x, ref.y - 45, 130, 100);


	//BORDURE

	context.fillStyle = 'black';
	context.fillRect(ref.x - 20, ref.y - 45, 10, 110);
	context.fillRect(ref.x - 10, ref.y - 55, 10, 10);
	context.fillRect(ref.x, ref.y - 65, 130, 10);
	context.fillRect(ref.x + 130, ref.y - 55, 10, 10);
	context.fillRect(ref.x - 10, ref.y + 55, 10, 10);
	context.fillRect(ref.x, ref.y + 65, 140, 10);;
	context.fillRect(ref.x + 140, ref.y - 45, 10, 110);
	context.fillRect(ref.x - 10, ref.y + 65, 10, 10);

	//POINTS ROSE SUR LE CORP

	context.fillStyle = '#ff3399';
	context.fillRect(ref.x + 15, ref.y - 25, 10, 10);
	context.fillRect(ref.x + 55, ref.y - 25, 10, 10);
	context.fillRect(ref.x + 85, ref.y - 35, 10, 10);
	context.fillRect(ref.x + 45, ref.y, 10, 10);
	context.fillRect(ref.x + 20, ref.y + 35, 10, 10);
	context.fillRect(ref.x + 55, ref.y + 25, 10, 10);
	context.fillRect(ref.x + 10, ref.y + 15, 10, 10);
	context.fillRect(ref.x + 100, ref.y - 15, 10, 10);
	context.fillRect(ref.x + 30, ref.y, 10, 10);
	context.fillRect(ref.x + 40, ref.y - 40, 10, 10);
	context.fillRect(ref.x + 45, ref.y + 40, 10, 10);

	//RETOUCHE

	context.fillStyle = '#ffcc99';
	context.fillRect(ref.x, ref.y - 45, 10, 10);
	context.fillRect(ref.x, ref.y - 35, 10, 10);
	context.fillRect(ref.x + 10, ref.y - 45, 10, 10);

	//RETOUCHE

	context.fillRect(ref.x, ref.y + 35, 10, 10);
	context.fillRect(ref.x + 10, ref.y + 45, 10, 10);
	context.fillRect(ref.x, ref.y + 45, 10, 10);

	//RETOUCHE

	context.fillRect(ref.x + 120, ref.y - 45, 10, 10);
	context.fillRect(ref.x + 120, ref.y - 35, 10, 10);
	context.fillRect(ref.x + 110, ref.y - 45, 10, 10);

	//PATE AVANT DROIT

	context.fillStyle = '#a6a6a6';
	context.fillRect(ref.x + 80, ref.y + 75, 20, 10);

	context.fillStyle = 'black';
	context.fillRect(ref.x + 80, ref.y + 85, 20, 10);
	context.fillRect(ref.x + 70, ref.y + 75, 10, 20);
	context.fillRect(ref.x + 100, ref.y + 75, 10, 10);

	// PATE AVANT GAUCHE 

	context.fillStyle = '#a6a6a6';
	context.fillRect(ref.x + 130, ref.y + 75, 20, 10);
	context.fillRect(ref.x + 140, ref.y + 65, 10, 10);

	context.fillStyle = 'black';
	context.fillRect(ref.x + 130, ref.y + 85, 20, 10);
	context.fillRect(ref.x + 120, ref.y + 75, 10, 10);
	context.fillRect(ref.x + 150, ref.y + 65, 10, 30);

	// PATE BACK GAUCHE

	context.fillStyle = '#a6a6a6';
	context.fillRect(ref.x + 20, ref.y + 75, 20, 10);

	context.fillStyle = 'black';
	context.fillRect(ref.x + 20, ref.y + 85, 20, 10);
	context.fillRect(ref.x + 10, ref.y + 75, 10, 20);
	context.fillRect(ref.x + 40, ref.y + 75, 10, 10);

	// PATE BACK DROIT

	context.fillStyle = '#a6a6a6';
	context.fillRect(ref.x - 40, ref.y + 65, 30, 10);
	context.fillRect(ref.x - 30, ref.y + 55, 10, 10);
	context.fillRect(ref.x - 40, ref.y + 75, 20, 10);

	context.fillStyle = 'black';
	context.fillRect(ref.x - 50, ref.y + 65, 10, 20);
	context.fillRect(ref.x - 50, ref.y + 85, 30, 10);
	context.fillRect(ref.x - 20, ref.y + 75, 10, 10);
	context.fillRect(ref.x - 40, ref.y + 55, 10, 10);
	context.fillRect(ref.x - 30, ref.y + 45, 10, 10);

	//QUEUE

	context.fillStyle = '#a6a6a6';
	context.fillRect(ref.x - 40, ref.y - 5, 20, 20);
	context.fillRect(ref.x - 60, ref.y - 5, 20, 10);
	context.fillRect(ref.x - 70, ref.y - 25, 20, 20);

	context.fillStyle = 'black';
	context.fillRect(ref.x - 40, ref.y + 15, 20, 10);
	context.fillRect(ref.x - 50, ref.y - 15, 30, 10);
	context.fillRect(ref.x - 60, ref.y + 5, 20, 10);
	context.fillRect(ref.x - 70, ref.y - 5, 10, 10);
	context.fillRect(ref.x - 80, ref.y - 25, 10, 20);
	context.fillRect(ref.x - 70, ref.y - 35, 20, 10);
	context.fillRect(ref.x - 50, ref.y - 25, 10, 10);


	// TETE BORDURE

	context.fillRect(ref.x + 100, ref.y - 25, 40, 10);
	context.fillRect(ref.x + 90, ref.y - 35, 10, 10);
	context.fillRect(ref.x + 140, ref.y - 35, 10, 10);
	context.fillRect(ref.x + 150, ref.y - 45, 10, 10);
	context.fillRect(ref.x + 160, ref.y - 55, 20, 10);
	context.fillRect(ref.x + 180, ref.y - 45, 10, 30);
	context.fillRect(ref.x + 190, ref.y - 15, 10, 50);
	context.fillRect(ref.x + 180, ref.y + 35, 10, 10);
	context.fillRect(ref.x + 170, ref.y + 45, 10, 10);
	context.fillRect(ref.x + 70, ref.y + 55, 100, 10);
	context.fillRect(ref.x + 80, ref.y - 45, 10, 10);
	context.fillRect(ref.x + 60, ref.y - 55, 20, 10);
	context.fillRect(ref.x + 50, ref.y - 45, 10, 30);
	context.fillRect(ref.x + 40, ref.y - 15, 10, 50);
	context.fillRect(ref.x + 50, ref.y + 35, 10, 10);
	context.fillRect(ref.x + 60, ref.y + 45, 10, 10);


	// TETE REMPLISSAGE

	context.fillStyle = '#999999';
	context.fillRect(ref.x + 70, ref.y - 5, 100, 60);
	context.fillRect(ref.x + 50, ref.y - 5, 20, 40);
	context.fillRect(ref.x + 170, ref.y - 5, 20, 40);
	context.fillRect(ref.x + 60, ref.y - 35, 20, 30);
	context.fillRect(ref.x + 160, ref.y - 35, 20, 30);
	context.fillRect(ref.x + 150, ref.y - 25, 10, 20);
	context.fillRect(ref.x + 80, ref.y - 25, 10, 20);
	context.fillRect(ref.x + 90, ref.y - 15, 10, 10);
	context.fillRect(ref.x + 140, ref.y - 15, 10, 10);
	context.fillRect(ref.x + 60, ref.y + 35, 120, 10);
	context.fillRect(ref.x + 100, ref.y - 15, 40, 10);
	context.fillRect(ref.x + 150, ref.y - 35, 10, 20);
	context.fillRect(ref.x + 160, ref.y - 45, 20, 10);
	context.fillRect(ref.x + 60, ref.y - 45, 20, 10);
	context.fillRect(ref.x + 80, ref.y - 35, 10, 10);
	context.fillRect(ref.x + 90, ref.y - 25, 10, 10);
	context.fillRect(ref.x + 50, ref.y - 15, 140, 10);
	context.fillRect(ref.x + 140, ref.y - 25, 10, 10);

	// TETE

	context.fillStyle = 'black';
	context.fillRect(ref.x + 150, ref.y - 5, 20, 20);
	context.fillRect(ref.x + 80, ref.y - 5, 20, 20);
	context.fillRect(ref.x + 130, ref.y + 5, 10, 10);
	context.fillRect(ref.x + 90, ref.y + 35, 70, 10);
	context.fillRect(ref.x + 90, ref.y + 25, 10, 20);
	context.fillRect(ref.x + 150, ref.y + 25, 10, 20);
	context.fillRect(ref.x + 120, ref.y + 25, 10, 20);

	context.fillStyle = '#FFFFFF';
	context.fillRect(ref.x + 150, ref.y - 5, 10, 10);
	context.fillRect(ref.x + 80, ref.y - 5, 10, 10);

	context.fillStyle = '#ff9999';
	context.fillRect(ref.x + 170, ref.y + 15, 20, 20);
	context.fillRect(ref.x + 60, ref.y + 15, 20, 20);

}

function text() {
	var text = 'FEKIH - L3 MIAGE - CHAT NYAN';
	context.fillStyle = 'hsl(' + (Math.random() * 360) + ',100%,50%)';
	context.font = '60px Arial';
	context.textAlign = 'center';
	context.textBaseLine = 'top';
	context.fillText(text, context.canvas.width / 2, 150);
}
function text_description() {
	var text = 'Cliquez pour prendre le controle du chat';
	context.fillStyle = 'hsl(' + (Math.random() * 360) + ',100%,50%)';
	context.font = '30px Arial';
	context.textAlign = 'center';
	context.textBaseLine = 'top';
	context.fillText(text, context.canvas.width / 2, 200);

}

// ============== BOUCLE ================= //


function loop() {
	requestAnimationFrame(loop);
	create_tail();
	create_star();
	star();
	draw();
	nyan();
	text();
	text_description();
	remove_tail();
	delete_star();

	if (iter) {
		ref.x = mouse.x;
		ref.y = mouse.y;
		refTail.x = mouse.x;
		refTail.y = mouse.y;
	} else {
		ref.x = context.canvas.width / 2;
		ref.y = context.canvas.height / 2;
		refTail.x = context.canvas.width / 2;
		refTail.y = context.canvas.height / 2;
	}
}
requestAnimationFrame(loop);