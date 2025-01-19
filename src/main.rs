use macroquad::prelude::*;

mod delta;
mod camera;
mod position;

#[macroquad::main("RustmonRed")]
async fn main() {
    let mut camera =  camera::create();
    let mut delta = delta::create();

    loop {
        delta.update();
        clear_background(BLACK);

        camera.draw_line_at(0.0, 0.0, 
            100.0, 100.0, 15.0, BLUE);        
        camera.set_position(camera.get_x() + 0.5, camera.get_y());
        next_frame().await
    }
}