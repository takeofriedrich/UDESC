class Particle {
  constructor() {
    this.primaryColor = [random(255), random(255), random(255), 100];
    this.secondaryColor = [random(255), random(255), random(255), 70];
    this.pos = createVector(random(width), random(height));
    this.rays = [];
    for (let a = 0; a < 360; a += 1) {
      this.rays.push(new Ray(this.pos, radians(a)));
      this.rays.push(new Ray(this.pos, radians(a + 0.5)));
    }
  }

  update(x, y) {
    this.pos.set(x, y);
  }

  getPos() {
    return this.pos;
  }

  look(walls) {
    for (let i = 0; i < this.rays.length; i += 1) {
      const ray = this.rays[i];
      let closest = null;
      let record = Infinity;
      let intercep = false;
      let j = 0;
      for (let wall of walls) {
        const pt = ray.cast(wall);
        if (pt) {
          const d = p5.Vector.dist(this.pos, pt);
          if (d < record) {
            record = d;
            closest = pt;
            if (j < 4) {
              intercep = true;
            } else {
              intercep = false;
            }
          }
        }
        j++;
      }
      if (closest) {
        if (!intercep) {
          stroke(this.primaryColor[0], this.primaryColor[1], this.primaryColor[2], this.primaryColor[3]);
        } else {
          stroke(this.secondaryColor[0], this.secondaryColor[1], this.secondaryColor[2], this.secondaryColor[3]);
        }
        line(this.pos.x, this.pos.y, closest.x, closest.y);
      }
    }
  }

  showLines() {
    for (let ray of this.rays) {
      ray.show();
    }
  }

  showElipses() {
    fill(255);
    ellipse(this.pos.x, this.pos.y, 4);
  }

}
