var catHeight = 150 // 150
var catOffset = 200
 
ctx.fillStyle = '#002E68'
ctx.fillRect(0, 0, ctx.canvas.width, ctx.canvas.height)
 
// rainbow

var rainbowColors = [
	'#FF0000',
  '#FF9100',
  '#F8FF00',
  '#00FF00',
  '#0091FF',
  '#7D00FF'
]
 
rainbowColors.forEach(function(color, index) {
	ctx.fillStyle = color
	ctx.fillRect(0, 50 + index * catHeight / 6, catOffset + 20, catHeight / 6)
})

// cat

ctx.translate(catOffset, 0)
 
 
// feet

ctx.fillStyle = '#999999'
ctx.lineWidth = 12
drawCircle(40, 208 - 150 + catHeight, 13)
  ctx.stroke()
  ctx.fill()
drawCircle(09, 208 - 150 + catHeight, 13)
ctx.stroke()
ctx.fill()
drawCircle(160, 205 - 150 + catHeight, 13)
ctx.stroke()
ctx.fill()
drawCircle(120, 207 - 150 + catHeight, 13)
ctx.stroke()
ctx.fill()
 
ctx.fillStyle = '#FFC993'
ctx.strokeStyle = "black"
drawRect(0, 50, 190, catHeight, 20)
ctx.stroke()
ctx.fill()

ctx.fillStyle = '#FF7DFD'
drawRect(10, 60, 170, catHeight - 20, 30)
ctx.fill()


// dots
ctx.fillStyle = '#FF00A0'
drawCircle(20, 150, 8)
ctx.fill()
drawCircle(50, 120, 8)
ctx.fill()
drawCircle(90, 140, 8)
ctx.fill()
drawCircle(90, 80, 8)
ctx.fill()
drawCircle(30, 100, 8)
ctx.fill()
drawCircle(130, 90, 8)
ctx.fill()
drawCircle(70, 170, 8)
ctx.fill()
 
 
// head 


var headY = -4

ctx.fillStyle = '#999999'
ctx.beginPath()
ctx.arc(170, headY + 10 + catHeight, 45, -0.3, Math.PI + 0.3)
ctx.lineTo(130, headY + 115 - 150 + catHeight)
ctx.lineTo(155, headY + 133 - 150 + catHeight)
ctx.lineTo(185, headY + 133 - 150 + catHeight)
ctx.lineTo(208, headY + 114 - 150 + catHeight)
ctx.lineTo(213, headY + 149 - 150 + catHeight)
ctx.stroke()
ctx.fill()
 
ctx.fillStyle = '#FF8B93'
drawCircle( - 70 + 210, headY + 175 - 150 + catHeight, 10)
ctx.fill()
drawCircle( - 70 + 270, headY + 175 - 150 + catHeight, 10)
ctx.fill()
 
ctx.fillStyle = 'black'
drawCircle( - 70 + 260, headY + 158 - 150 + catHeight, 7)
ctx.fill()
drawCircle( - 70 + 220, headY +158 - 150 + catHeight, 7)
ctx.fill()

// mouth
ctx.lineWidth = 5
ctx.beginPath()
ctx.arc(  + 5 + 155, headY + 184 - 150 + catHeight, 10, 2*Math.PI, 3 * Math.PI)
ctx.stroke()
ctx.beginPath()
ctx.arc(  + 5 + 175, headY + 184 - 150 + catHeight, 10, 2*Math.PI, 3 * Math.PI)
ctx.stroke()



 
function drawCircle(x, y, r) {
	ctx.beginPath()
	ctx.arc(x, y, r, 0, 2*Math.PI)
}

function drawRect(x,y,width,height,r) {
	ctx.beginPath()
  ctx.moveTo(x+r,y)
  ctx.lineTo(x+width-r,y)
  ctx.arc(x+width-r,y+r, r, 1.5 * Math.PI, 2*Math.PI)
  ctx.lineTo(x+width,y+height-r)
  ctx.arc(x+width-r,y+height-r, r, 2 * Math.PI, 2.5 * Math.PI)
  ctx.lineTo(x+r,y+height)
  ctx.arc(x+r,y+height-r, r, 2.5 * Math.PI, 3 * Math.PI)
  ctx.lineTo(x,y+r)
  ctx.arc(x+r,y+r, r, 3 * Math.PI, 3.5 * Math.PI)
}