(function(){
  angular.module('editor', ["contenteditable", "LocalStorageModule", 'colorpicker.module', 'ngSanitize'])
    .controller('mainController', mainController)
    .config(function (localStorageServiceProvider) {
    localStorageServiceProvider
      .setPrefix('editor')
    })
    .filter('reverse', function() {
      return function(items) {
        return items.slice().reverse();
      };
    });
  function mainController($scope, $rootScope, localStorageService, $interval, $timeout){
    var vm = this;
    vm.loading = true;

    vm.sprites = [];
    vm.palettes = [];
    vm.backgrounds = [];
    vm.code = "";
    vm.previewX = 1;
    vm.previewY = 1;

    vm.range = function(min, max, step) {
      step = step || 1;
      var input = [];
      for (var i = min; i <= max; i += step) {
          input.push(i);
      }
      return input;
  };

    vm.resetSprites = function(){
      if(confirm("Tem certeza? Não pode ser desfeito.")){

        vm.sprites = [];
        for(var i=0;i<128;i++){
          vm.newSprite();
        }
        vm.loadSprite(0);
      }

    }

    vm.resetPalettes = function(){
      if(confirm("Tem certeza? Não pode ser desfeito.")){
        vm.palettes = [];
        for(var i=0;i<32;i++){
          vm.addPalette();
        }

        vm.loadPalette(0);
      }
    }

    vm.resetCurrentPalette = function(){
      if(confirm("Tem certeza? Não pode ser desfeito.")){
        angular.forEach(vm.currentPalette.colors, function(color, key){
          color.value = "";
          color.color = "";
        });
      }
    }

    vm.resetCurrentSprite = function(){
      if(confirm("Tem certeza? Não pode ser desfeito.")){
        angular.forEach(vm.currentSprite.rows, function(row, key){
          angular.forEach(row.cols, function(col, key){
            col.val = "";
            col.color = "";
          });
        });
      }
    }

    vm.genOam = function(){
      vm.code = "oam"+vm.currentSprite.id+" : var #2048<br>\
        static oam"+vm.currentSprite.id+" + #0, #0 ;X<br>\
        static oam"+vm.currentSprite.id+" + #1, #0 ;Y<br>\
        static oam"+vm.currentSprite.id+" + #2, #"+vm.currentSprite.id+" ;Sprite<br>\
        static oam"+vm.currentSprite.id+" + #3, #"+(vm.currentSprite.h*256+vm.currentSprite.h*512+parseInt(vm.currentSprite.palette))+" ;HV-Paleta<br>";
    }

    vm.genBG = function(){
      vm.code = vm.currentSprite.h*256+vm.currentSprite.h*512+parseInt(vm.currentSprite.id)+parseInt(vm.currentSprite.palette)*1024;
    }

    vm.newSprite = function(){
      var sprite = {
        id: vm.sprites.length,
        palette: 0,
        rows: []
      }
      for(var i=0;i<8;i++){
        var row = {
          id: sprite.rows.length,
          cols: []
        };
        for(var j=0;j<8;j++){
          row.cols.push({
            id: row.cols.length,
            val: ""
          });
        }
        sprite.rows.push(row);
      }
      vm.sprites.push(sprite);
    }

    vm.col=1;

    vm.addPalette = function(){
      vm.palettes.push({
        id: vm.palettes.length,
        colors: [
          {
            id: "1",
            value: "",
            color: "0"
          },{
            id: "2",
            value: "",
            color: "0"
          },{
            id: "3",
            value: "",
            color: "0"
          }
        ]
      })
    }

    vm.loadSprite = function(id){
      vm.code = "";
      vm.currentSprite = vm.sprites[id];
      vm.currentSprite.v = 0;
      vm.currentSprite.h = 0;
    }

    vm.loadPalette = function(id){
      vm.currentPalette = vm.palettes[id];
    }

    vm.save = function(){
      localStorageService.set("sprites", vm.sprites);
      localStorageService.set("palettes", vm.palettes);
      localStorageService.set("backgrounds", vm.backgrounds);
    }

    vm.load = function(){
      vm.sprites = localStorageService.get("sprites");
      vm.palettes = localStorageService.get("palettes");
      vm.backgrounds = localStorageService.get("backgrounds");

      if(vm.sprites == null || vm.palettes == null || vm.sprites.length == 0 || vm.palettes.length == 0){
        vm.sprites = [];
        vm.palettes = [];
        for(var i=0;i<128;i++){
          vm.newSprite();
        }

        for(var i=0;i<32;i++){
          vm.addPalette();
        }
      }
      vm.loadSprite(0);
      vm.loadPalette(0);
    }

    vm.genCode = function(){
      $("#source").html("");
      $("#source").append("sprites : var #2048<br>");
      angular.forEach(vm.sprites, function(sprite, spriteId){
        angular.forEach(sprite.rows, function(row, rowId){
          var num = 0;
          angular.forEach(row.cols, function(col, colId){
            num += Math.pow(parseInt(col.val/2)*2, 16-col.id)/2+Math.pow(parseInt(col.val%2)*2, 8-col.id)/2;
          })
          $("#source").append("static sprites + #"+(sprite.id*8+row.id)+", #"+num+"<br>");
        });
      });

      $("#source").append("<br><br>palettes : var #128<br>");
      angular.forEach(vm.palettes, function(palette, key){
        $("#source").append("static palettes + #"+(key*4+1)+", #"+palette.colors[0].color+"<br>");
        $("#source").append("static palettes + #"+(key*4+2)+", #"+palette.colors[1].color+"<br>");
        $("#source").append("static palettes + #"+(key*4+3)+", #"+palette.colors[2].color+"<br>");
      });
    }

    vm.updateColors = function(){
      angular.forEach(vm.currentSprite.rows, function(row, rowId){
        angular.forEach(row.cols, function(col, colId){
          if(col.val && col.val>0){
            var re = /rgb\(([0-9]{0,3}),([0-9]{0,3}),([0-9]{0,3})\)/g;
            var m = re.exec(vm.palettes[vm.currentSprite.palette].colors[col.val-1].value);
            if(m){
              vm.palettes[vm.currentSprite.palette].colors[col.val-1].color = parseInt(m[3]/256*32)+parseInt(m[2]/256*32)*32+parseInt(m[1]/256*32)*32*32;
              col.color = vm.palettes[vm.currentSprite.palette].colors[col.val-1].value;
            }else{
              col.color = "";
            }
          }else{
            col.color = "";
          }
        });
      });
      vm.change=true;
    };
    $interval(function(){
      vm.save();
      if(vm.change){

        vm.genCode();
        vm.change=false;
      }
    }, 2000);


    $timeout(function(){
      vm.load();
      vm.updateColors();
      vm.loading = false;
    })
  }
})()
