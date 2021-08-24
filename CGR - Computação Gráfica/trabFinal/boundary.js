class Boundary {
  constructor(x1, y1, x2, y2) {
    this.a = createVector(x1, y1);
    this.b = createVector(x2, y2);
  }

  show() {
    stroke(255);
    line(this.a.x, this.a.y, this.b.x, this.b.y);
  }

  getPosA() {
    return this.a;
  }

  getPosB() {
    return this.b;
  }

  updateA(x, y) {
    this.a.set(x, y);
  }

  updateB(x, y) {
    this.b.set(x, y);
  }
}
