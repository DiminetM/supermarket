module.exports = (grunt) ->

  # Load all grunt tasks
  require('load-grunt-tasks')(grunt)

  # Show elapsed time at the end
  require('time-grunt')(grunt)

  # Project configuration.
  grunt.initConfig
    pkg: grunt.file.readJSON('package.json')
    banner: '/*! <%= pkg.name %> - v<%= pkg.version %> - ' +
      '<%= grunt.template.today("yyyy-mm-dd") %>\n' +
      '<%= pkg.homepage ? "* " + pkg.homepage + "\\n" : "" %>' +
      '* Copyright (c) <%= grunt.template.today("yyyy") %> <%= pkg.author.name %>;' +
      ' Licensed MIT */\n'

    # Task configuration
    less:
      development:
        options:
          sourceMap: true
          cleancss: true
        files:
          'styles/css/base.css': 'styles/less/base.less'
          'styles/css/drupal.css': 'styles/less/drupal.less'
          'styles/css/extend.css': 'styles/less/extend.less'
          'styles/css/fonts.css': 'styles/less/fonts.less'
          'styles/css/forms.css': 'styles/less/forms.less'
          'styles/css/grid.css': 'styles/less/grid.less'
          'styles/css/main.css': 'styles/less/main.less'
          'styles/css/modal.css': 'styles/less/modal.less'
          'styles/css/nav.css': 'styles/less/nav.less'
          'styles/css/nodes.css': 'styles/less/nodes.less'
          'styles/css/panels.css': 'styles/less/panels.less'
          'styles/css/print.css': 'styles/less/print.less'
          'styles/css/radius.css': 'styles/less/radius.less'
          'styles/css/reset.css': 'styles/less/reset.less'
          'styles/css/views.css': 'styles/less/views.less'
          'styles/css/wysiwyg.css': 'styles/less/wysiwyg.less'
    autoprefixer:
      options:
        browsers: [
          'last 2 version'
          'ie 8'
          'ie 9'
        ]
        map: true
      css:
        expand: true
        flatten: true
        src: 'styles/css/*.css'
        dest: 'styles/css/'
    watch:
      gruntfile:
        files: ['Gruntfile.coffee']
      less:
        files: [
          'styles/less/*.less'
        ]
        tasks: [
          'less'
          'autoprefixer'
        ]
        options:
          livereload: true

  # Register tasks
  grunt.registerTask('dev',
    [
      'less'
      'autoprefixer'
      'watch'
    ])
  return
