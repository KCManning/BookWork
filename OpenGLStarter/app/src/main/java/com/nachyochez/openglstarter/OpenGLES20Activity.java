package com.nachyochez.openglstarter;

import android.opengl.GLSurfaceView;

/**
 * Created by Kevin on 1/7/2016.
 */
public class OpenGLES20Activity extends Activity
{
    private GLSurfaceView mGLView;

    @Override
    public void OnCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        //Creates a GLSurfaceView instance and set it as the contentView
        mGLView = new MyGlSurfaceView(this);
        setContentView(mGLView);
    }
}
