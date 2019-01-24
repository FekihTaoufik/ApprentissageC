
class Polynome {
	double a, b, c;

	Polynome(double a, double b, double c) {
		this.a = a;
		this.b = b;
		this.c = c;

	}

	double delta() {
		return (b * b) - 4 * a * c;
	}

	double evaluer(double x) {
		return a * (x * x) + b * x + c;
	}

	double racineReelle2(double x) {
		double d = this.delta();
		if (d > 0) {
			return (-b + Math.sqrt(d)) / (2 * a);
		} else if (d == 0) {
			return -b / (2 * a);
		} else {
			return Double.NaN;
		}
	}

	double racineReelle1(double x) {
		double d = this.delta();
		if (d > 0) {
			return (-b - Math.sqrt(d)) / (2 * a);
		} else if (d == 0) {
			return -b / (2 * a);
		} else {
			return Double.NaN;
		}
	}

	Complexe racine1(double x) {
		double d = this.delta();
		if (d < 0) {
			return new Complexe(-b / (2 * a), (-Math.sqrt(-d)) / (2 * a));
		} else {
			return new Complexe(-b / (2 * a), 0);
		}
	}

	Complexe racine2(double x) {
		double d = this.delta();
		if (d < 0) {
			return new Complexe(-b / (2 * a), (Math.sqrt(-d)) / (2 * a));
		} else {
			return new Complexe(-b / (2 * a), 0);
		}
	}
}
