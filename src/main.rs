use macroquad::prelude::*;

use crate::renderer::Renderer; // Make sure this import is included

mod delta;
mod camera;
mod position;
mod renderer;

#[macroquad::main("RustmonRed")]
async fn main() {
    let mut camera =  camera::create();
    let mut delta = delta::create();
    let renderer = renderer::basic::create();

    delta.set_multiplier(1.0);
    loop {
        clear_background(BLACK);
        delta.update();
        renderer.render(&mut camera, &mut delta);

        camera.set_position(camera.get_x() + 0.5, camera.get_y());
        next_frame().await
    }
}
