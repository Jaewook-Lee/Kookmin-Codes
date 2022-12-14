# Origin sources : https://github.com/SCKIMOSU/Numerical-Analysis/blob/master/regression_class.py
##-----------------
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf

def Data_Genearion(num_points):
    #num_points = 50
    vectors_set = []
    for i in np.arange(num_points):
        x = np.random.normal(2, 2) + 10 # Adding 10 indicates moving the mean in a positive direction by 10.
        y = x * 5 + (np.random.normal(0, 3)) * 2
        vectors_set.append([x, y])

    x_data = [v[0] for v in vectors_set]
    y_data = [v[1] for v in vectors_set]

    return  x_data, y_data



def Data_Draw(x_data, y_data):
    plt.plot(x_data, y_data,'ro')
    plt.ylim([0,100])
    plt.xlim([0,25])
    plt.xlabel('x')
    plt.ylabel('y')
    #plt.legend()
    plt.show()


def Data_Learning(x_data, y_data):
    W = tf.Variable(tf.random_uniform([1], -1.0, 1.0))
    b = tf.Variable(tf.zeros([1]))
    y = W * x_data + b
    loss = tf.reduce_mean(tf.square(y - y_data))
    #lo.append(loss)
    optimizer = tf.train.GradientDescentOptimizer(0.0015)
    train = optimizer.minimize(loss)
    init = tf.global_variables_initializer()
    sess = tf.Session()
    sess.run(init)

    train_set = []  ###
    for step in np.arange(10):
        sess.run(train)
        print(step, sess.run(W), sess.run(b))
        print(step, sess.run(loss))
        train_set.append([sess.run(W), sess.run(b), sess.run(loss)])  ###

        plt.plot(x_data, y_data, 'ro')
        plt.plot(x_data, sess.run(W) * x_data + sess.run(b))
        plt.xlabel('x')
        plt.ylabel('y')
        #plt.legend()
        plt.show()

    W_data = [t[0] for t in train_set]
    v_data = [t[1] for t in train_set]
    Loss_data= [t[2] for t in train_set]

    return W_data,v_data, Loss_data


if __name__ == '__main__':
    num_points=50
    x_data, y_data=Data_Genearion(num_points)
    Data_Draw(x_data, y_data)

    W_data, v_data, Loss_data = Data_Learning(x_data, y_data)

    #for step in np.arange(10):

        #W_data[step]
    print('W_data = ', W_data)
    print('v_data = ', v_data)
print('Loss_data = ', Loss_data)