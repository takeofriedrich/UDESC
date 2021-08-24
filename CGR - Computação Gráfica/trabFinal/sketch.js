let walls = [];
let ray;
let particles = [];
let r = 40;
let mouseDown = false;
let iParticle = -1;
let iObstacle = -1;
let obstacleA = true;
let bestDist = r;

function setup() {
  createCanvas(800, 800);
  addParticleBt = createButton("Adicionar Particula");
  addParticleBt.position(5, height + 5);
  addParticleBt.mousePressed(addParticle);

  removeParticleBt = createButton("Remover Particula");
  removeParticleBt.position(150, height + 5);
  removeParticleBt.mousePressed(removeParticle);

  addObstacleBt = createButton("Adicionar Obstáculo");
  addObstacleBt.position(5, height + 35);
  addObstacleBt.mousePressed(addObstacle);

  removeObstacleBt = createButton("Remover Obstáculo");
  removeObstacleBt.position(150, height + 35);
  removeObstacleBt.mousePressed(removeObstacle);

  walls.push(new Boundary(-1, -1, width, -1));
  walls.push(new Boundary(width, -1, width, height));
  walls.push(new Boundary(width, height, -1, height));
  walls.push(new Boundary(-1, height, -1, -1));

  for (let i = 0; i < 2; i++) {
    let x1 = random(width);
    let x2 = random(width);
    let y1 = random(height);
    let y2 = random(height);
    walls.push(new Boundary(x1, y1, x2, y2));
  }

  for (let i = 0; i < 1; i++) {
    particles.push(new Particle());
  }
}

function addParticle() {
  particles.push(new Particle());
}

function removeParticle() {
  if (particles.length > 0)
    particles.splice(floor(random(particles.length)), 1);
}

function addObstacle() {
  let x1 = random(width);
  let x2 = random(width);
  let y1 = random(height);
  let y2 = random(height);
  walls.push(new Boundary(x1, y1, x2, y2));
}

function removeObstacle() {
  let pos = 4 + floor(random(walls.length - 4));
  console.log(pos);
  if (walls.length >= 4)
    walls.splice(pos, 1);
}

function mouseReleased() {
  mouseDown = false;
  iParticle = -1;
  iObstacle = -1;
  obstacleA = true;
}

function mousePressed() {
  let mousePos = createVector(mouseX, mouseY);
  for (let i = 0; i < particles.length; i++) {
    if (bestDist > mousePos.dist(particles[i].getPos())) {
      iParticle = i;
      bestDist = mousePos.dist(particles[i].getPos());
    }
  }

  for (let i = 0; i < walls.length; i++) {
    if (bestDist > mousePos.dist(walls[i].getPosA())) {
      iParticle = -1;
      iObstacle = i;
      obstacleA = true;
      bestDist = mousePos.dist(walls[i].getPosA());
    }
    if (bestDist > mousePos.dist(walls[i].getPosB())) {
      iParticle = -1;
      iObstacle = i;
      obstacleA = false;
      bestDist = mousePos.dist(walls[i].getPosB());
    }
  }
  bestDist = r;
  if (iParticle != -1 || iObstacle != -1) {
    mouseDown = true;
  }
}

function mouseDragged() {
  if (mouseDown) {
    if (iParticle != -1)
      particles[iParticle].update(mouseX, mouseY);
    else if (iObstacle != -1) {
      if (obstacleA)
        walls[iObstacle].updateA(mouseX, mouseY);
      else
        walls[iObstacle].updateB(mouseX, mouseY);
    }
  }
}

function draw() {
  background(0);
  for (let wall of walls) {
    wall.show();
  }
  for (let i = 0; i < particles.length; i++) {
    particles[i].showElipses();
    particles[i].showLines();
    particles[i].look(walls);
  }
}
