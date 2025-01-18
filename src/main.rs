use macroquad::prelude::*;

mod camera;
mod position;

#[macroquad::main("RustmonRed")]
async fn main() {
    let mut camera =  camera::create_camera();
    loop {
        clear_background(BLACK);

        camera.draw_line_at(0.0, 0.0, 
            100.0, 100.0, 15.0, BLUE);        
        camera.set_position(camera.get_x() + 0.5, camera.get_y());
        next_frame().await
    }
}