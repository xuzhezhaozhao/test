fn main() {
    let x = HasDrop;
}

struct HasDrop;

impl Drop for HasDrop {
    fn drop(&mut self) {
        println!("Dropping.");
    }
}

struct Circle {
    x: f64,
    y: f64,
    radius: f64,
}

trait HasArea {
    fn area(&self) -> f64;
}

impl HasArea for Circle {
    fn area(&self) -> f64 {
        std::f64::consts::PI * (self.radius * self.radius)
    }
}

fn print_area<T: HasArea>(shape: T) {
    println!("This shapre has an area of {}", shape.area());
}

impl HasArea for i32 {
    fn area(&self) -> f64 {
        println!("this is i32 to f64.");
        *self as f64
    }
}
