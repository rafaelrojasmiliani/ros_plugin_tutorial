# This file tells docker what image must be created
# in order to be ahble to test this library
FROM ubuntu:18.04


ENV TZ=Europe/Rome
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
ENV UBUNTU_RELEASE=bionic
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends -o Dpkg::Options::="--force-confnew" \
                    gnupg
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $UBUNTU_RELEASE main" > /etc/apt/sources.list.d/ros-latest.list'
RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
RUN apt-get update

# Install packages
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends -o Dpkg::Options::="--force-confnew" \
                    ros-melodic-desktop-full ros-melodic-moveit-setup-assistant iputils-ping net-tools netcat screen build-essential
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends -o Dpkg::Options::="--force-confnew" \
                   ros-melodic-cartographer-rviz ros-melodic-distance-map-rviz ros-melodic-grid-map-rviz-plugin ros-melodic-jsk-rviz-plugins ros-melodic-octomap-rviz-plugins ros-melodic-rviz-visual-tools
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends -o Dpkg::Options::="--force-confnew" \
                    ros-melodic-ompl ros-melodic-moveit-planners ros-melodic-moveit-commander python-catkin-tools
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends -o Dpkg::Options::="--force-confnew" \
                    python-rosinstall-generator python-rosinstall python-rosdep ros-melodic-moveit-visual-tools 
# user handling
ARG myuser
ARG myuid
ARG mygroup
ARG mygid
ARG scriptdir
RUN addgroup --gid ${mygid} ${mygroup} --force-badname
RUN adduser --gecos "" --disabled-password  --uid ${myuid} --gid ${mygid} ${myuser} --force-badname
#add user to sudoers
RUN echo "${myuser} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
RUN echo "source /opt/ros/melodic/setup.bash" >> /etc/bash.bashrc
WORKDIR /


COPY ./configfiles/screenrc /root/.screenrc
COPY ./configfiles/screenrc /home/${myuser}/.screenrc
